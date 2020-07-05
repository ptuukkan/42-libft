/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:18:13 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 17:18:15 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_d(va_list *ap, t_flags *flags)
{
	intmax_t	i;

	i = 0;
	if (flags->length == 0)
		i = (intmax_t)va_arg(*ap, int);
	else if (flags->length == L)
		i = (intmax_t)va_arg(*ap, long);
	else if (flags->length == H)
		i = (intmax_t)(short)va_arg(*ap, int);
	else if (flags->length == HH)
		i = (intmax_t)(signed char)va_arg(*ap, int);
	else if (flags->length == LL)
		i = (intmax_t)va_arg(*ap, long long);
	else if (flags->length == J)
		i = va_arg(*ap, intmax_t);
	else if (flags->length == Z)
		i = (intmax_t)va_arg(*ap, ssize_t);
	return (i);
}

uintmax_t	get_u(va_list *ap, t_flags *flags)
{
	uintmax_t	u;

	u = 0;
	if (flags->length == 0)
		u = (uintmax_t)va_arg(*ap, unsigned int);
	else if (flags->length == L)
		u = (uintmax_t)va_arg(*ap, unsigned long);
	else if (flags->length == H)
		u = (uintmax_t)(unsigned short)va_arg(*ap, unsigned int);
	else if (flags->length == HH)
		u = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else if (flags->length == LL)
		u = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (flags->length == J)
		u = va_arg(*ap, uintmax_t);
	else if (flags->length == Z)
		u = (uintmax_t)va_arg(*ap, size_t);
	return (u);
}

double		get_f(va_list *ap, t_flags *flags)
{
	double		dbl;
	uint64_t	u;

	dbl = 0;
	dbl = va_arg(*ap, double);
	ft_memcpy(&u, &dbl, sizeof(double));
	if ((u >> 63) & 1)
	{
		flags->sign = 1;
		flags->signch = '-';
	}
	return (dbl);
}

long double	get_lf(va_list *ap, t_flags *flags)
{
	long double		dbl;
	unsigned char	*c;
	char			sign;

	dbl = 0;
	dbl = va_arg(*ap, long double);
	c = (unsigned char *)&dbl;
	sign = (c[9] >> 7);
	if (sign)
	{
		flags->sign = 1;
		flags->signch = '-';
	}
	return (dbl);
}
