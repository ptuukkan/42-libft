/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_flags2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_flags_g(t_flags *flags)
{
	if (flags->precision_set == 1 && flags->precision == 0)
		flags->precision = 1;
	if (flags->precision_set == 0)
		flags->precision = 6;
}

static void	adjust_flags_ef(t_flags *flags)
{
	if (flags->precision_set == 0)
		flags->precision = 6;
}

static void	adjust_flags_a(t_flags *flags)
{
	if (flags->precision_set == 0)
		flags->precision = -1;
	flags->field -= 2;
}

void		adjust_flags2(t_flags *flags, char spec)
{
	if (spec == 'f' || spec == 'e' || spec == 'E')
		return (adjust_flags_ef(flags));
	if (spec == 'a' || spec == 'A')
		return (adjust_flags_a(flags));
	if (spec == 'g' || spec == 'G')
		return (adjust_flags_g(flags));
}
