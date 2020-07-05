/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_c(unsigned char c, t_flags *flags)
{
	flags->field -= 1;
	if (flags->leftadj == 0)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
	flags->printed += ft_putnchar(c, 1);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
}

void		convert_c(va_list *ap, t_flags *flags)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*ap, int);
	print_c(c, flags);
}
