/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_s(char *str, int len, t_flags *flags)
{
	int	min;

	min = len;
	if (flags->precision_set == 1)
	{
		min = ft_min(len, flags->precision);
	}
	flags->field -= min;
	if (flags->leftadj == 0)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
	flags->printed += write(1, str, min);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
}

void		convert_s(va_list *ap, t_flags *flags)
{
	char	*str;

	adjust_flags(flags, flags->spec);
	if (!(str = va_arg(*ap, char *)))
	{
		str = ft_strdup("(null)");
		print_s(str, ft_strlen(str), flags);
		free(str);
	}
	else
		print_s(str, ft_strlen(str), flags);
}
