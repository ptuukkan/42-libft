/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_flags_dux(t_flags *flags)
{
	if (flags->precision_set)
	{
		flags->zero = 0;
		flags->pad = ' ';
		if (flags->precision < 0)
			flags->precision = 0;
	}
}

static void	adjust_flags_p(t_flags *flags)
{
	flags->altform = 1;
}

static void	adjust_flags_s(t_flags *flags)
{
	if (flags->precision < 0)
		flags->precision_set = 0;
}

static void	adjust_flags_o(t_flags *flags)
{
	if (flags->precision_set)
	{
		flags->zero = 0;
		flags->pad = ' ';
		if (flags->precision < 0)
			flags->precision = 0;
	}
	if (flags->altform && flags->precision_set && flags->precision == 0)
		flags->precision = 1;
	if (flags->altform)
	{
		if (flags->precision_set)
			flags->precision--;
		flags->field--;
	}
}

void		adjust_flags(t_flags *flags, char spec)
{
	if (flags->leftadj)
	{
		flags->zero = 0;
		flags->pad = ' ';
	}
	if (spec == 's')
		return (adjust_flags_s(flags));
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X')
		return (adjust_flags_dux(flags));
	if (spec == 'o')
		return (adjust_flags_o(flags));
	if (spec == 'p')
		return (adjust_flags_p(flags));
	return (adjust_flags2(flags, spec));
}
