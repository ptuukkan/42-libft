/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_u(char *nb, int len, t_flags *flags)
{
	flags->field -= ft_max(flags->precision, len);
	flags->precision -= len;
	if (flags->leftadj == 0)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
	flags->printed += ft_putnchar('0', flags->precision);
	flags->printed += write(1, nb, len);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
}

void		convert_u(va_list *ap, t_flags *flags)
{
	uintmax_t	u;
	char		*nb;

	adjust_flags(flags, flags->spec);
	u = get_u(ap, flags);
	nb = NULL;
	if (!(nb = ft_ultoa_base(u, 10, 0)))
		return ;
	if (flags->precision_set == 1 && flags->precision == 0 && u == 0)
		nb[0] = '\0';
	print_u(nb, ft_strlen(nb), flags);
	free(nb);
}
