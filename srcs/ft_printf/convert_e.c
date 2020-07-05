/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_altform(char **nb)
{
	char	**tmp;

	if (!(tmp = ft_strsplit(*nb, 'e')))
		return ;
	ft_strdel(nb);
	*nb = ft_strnjoin(3, tmp[0], ".e", tmp[1]);
	ft_strarrdel(&tmp);
}

void		convert_e(double dbl, t_flags *flags)
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
	if (!(nb = convert_to_eformat(&nb, flags->precision, &e)))
		return ;
	if (flags->altform && flags->precision == 0)
		handle_altform(&nb);
	if (flags->spec == 'E')
		ft_strtoupper(nb);
	print_f(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}

void		convert_le(long double dbl, t_flags *flags)
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
	if (!(nb = convert_to_eformat(&nb, flags->precision, &e)))
		return ;
	if (flags->altform && flags->precision == 0)
		handle_altform(&nb);
	if (flags->spec == 'E')
		ft_strtoupper(nb);
	print_f(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}
