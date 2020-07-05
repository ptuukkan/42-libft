/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_prefix(t_flags *flags)
{
	if (flags->altform == 1)
		flags->printed += write(1, "0", 1);
}

static void		print_o(char *nb, int len, t_flags *flags)
{
	flags->field -= ft_max(flags->precision, len);
	flags->precision -= len;
	if (flags->leftadj == 0)
	{
		if (flags->zero == 0)
			flags->printed += ft_putnchar(flags->pad, flags->field);
		else
		{
			print_prefix(flags);
			flags->printed += ft_putnchar(flags->pad, flags->field);
		}
	}
	if (flags->zero == 0)
		print_prefix(flags);
	flags->printed += ft_putnchar('0', flags->precision);
	flags->printed += write(1, nb, len);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
}

void			convert_o(va_list *ap, t_flags *flags)
{
	uintmax_t	u;
	char		*nb;

	adjust_flags(flags, flags->spec);
	nb = NULL;
	u = get_u(ap, flags);
	if (!(nb = ft_ultoa_base(u, 8, 0)))
		return ;
	if (flags->precision_set == 1 && flags->precision == 0 && u == 0)
		nb[0] = '\0';
	if (flags->altform && u == 0)
		nb[0] = '\0';
	print_o(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}
