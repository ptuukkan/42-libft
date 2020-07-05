/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		convert_g(double dbl, t_flags *flags)
{
	char	*nb;
	int		e;

	if (!(nb = ft_dtoa(dbl, -1)))
		return ;
	if (ft_strstr(nb, "inf") || ft_strstr(nb, "nan"))
	{
		print_special(nb, ft_strlen(nb), flags);
		return ;
	}
	if (nb[0] == '-')
		remove_minus(&nb);
	e = get_dbl_exponent(nb);
	trim_gformat(&nb, ft_strlen(nb), flags->precision, &e);
	if (e >= flags->precision || e < -4)
		nb = convert_to_etype(&nb, e, flags);
	else
		nb = convert_to_ftype(&nb, flags);
	if (nb == NULL)
		return ;
	if (flags->spec == 'G')
		ft_strtoupper(nb);
	print_f(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}

void		convert_lg(long double dbl, t_flags *flags)
{
	char	*nb;
	int		e;

	if (!(nb = ft_ldtoa(dbl, -1)))
		return ;
	if (ft_strstr(nb, "inf") || ft_strstr(nb, "nan"))
	{
		print_special(nb, ft_strlen(nb), flags);
		return ;
	}
	if (nb[0] == '-')
		remove_minus(&nb);
	e = get_dbl_exponent(nb);
	trim_gformat(&nb, ft_strlen(nb), flags->precision, &e);
	if (e >= flags->precision || e < -4)
		nb = convert_to_etype(&nb, e, flags);
	else
		nb = convert_to_ftype(&nb, flags);
	if (nb == NULL)
		return ;
	if (flags->spec == 'G')
		ft_strtoupper(nb);
	print_f(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}
