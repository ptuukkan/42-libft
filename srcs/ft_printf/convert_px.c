/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_prefix(char x, t_flags *flags)
{
	if (flags->altform == 1)
	{
		flags->printed += write(1, "0", 1);
		flags->printed += write(1, &x, 1);
	}
}

static void	print_x(char *nb, int len, t_flags *flags, char x)
{
	flags->field -= ft_max(flags->precision, len) + (flags->altform * 2);
	flags->precision -= len;
	if (flags->leftadj == 0)
	{
		if (flags->zero == 0)
			flags->printed += ft_putnchar(flags->pad, flags->field);
		else
		{
			print_prefix(x, flags);
			flags->printed += ft_putnchar(flags->pad, flags->field);
		}
	}
	if (flags->zero == 0)
		print_prefix(x, flags);
	flags->printed += ft_putnchar('0', flags->precision);
	flags->printed += write(1, nb, len);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
}

void		convert_x(va_list *ap, t_flags *flags)
{
	uint64_t	u;
	char		*nb;

	adjust_flags(flags, flags->spec);
	u = get_u(ap, flags);
	nb = NULL;
	if (!(nb = ft_ultoa_base(u, 16, flags->spec)))
		return ;
	if (flags->altform == 1 && u == 0)
		flags->altform = 0;
	if (flags->precision_set == 1 && flags->precision == 0 && u == 0)
		nb[0] = '\0';
	print_x(nb, ft_strlen(nb), flags, flags->spec);
	ft_strdel(&nb);
}

void		convert_p(va_list *ap, t_flags *flags)
{
	uintmax_t	u;
	char		*nb;

	adjust_flags(flags, flags->spec);
	u = (uintmax_t)va_arg(*ap, void *);
	if (!(nb = ft_ultoa_base(u, 16, 0)))
		return ;
	if (flags->precision_set && flags->precision == 0 && u == 0)
		nb[0] = '\0';
	print_x(nb, ft_strlen(nb), flags, 'x');
	ft_strdel(&nb);
}
