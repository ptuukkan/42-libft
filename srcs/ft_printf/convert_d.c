/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_d(char *nb, int len, t_flags *flags)
{
	flags->field -= ft_max(flags->blank, flags->sign);
	flags->field -= ft_max(flags->precision, len);
	flags->precision -= len;
	if (flags->leftadj == 0)
	{
		if (flags->pad == '0' && (flags->sign == 1 || flags->blank == 1))
		{
			flags->printed += ft_putnchar(flags->signch, 1);
		}
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
	if (flags->pad == ' ' && (flags->sign == 1 || flags->blank == 1))
	{
		flags->printed += ft_putnchar(flags->signch, 1);
	}
	flags->printed += ft_putnchar('0', flags->precision);
	flags->printed += write(1, nb, len);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
}

void		convert_d(va_list *ap, t_flags *flags)
{
	intmax_t	i;
	char		*nb;

	adjust_flags(flags, flags->spec);
	i = get_d(ap, flags);
	if (!(nb = ft_ltoa(i)))
		return ;
	if (i < 0)
	{
		flags->sign = 1;
		flags->signch = '-';
		print_d(nb + 1, ft_strlen(nb + 1), flags);
	}
	else
	{
		if (flags->precision_set == 1 && flags->precision == 0 && i == 0)
			nb[0] = '\0';
		print_d(nb, ft_strlen(nb), flags);
	}
	ft_strdel(&nb);
}
