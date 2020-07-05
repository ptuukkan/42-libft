/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:34:24 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/06/23 14:34:25 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_rounding_overflow(char **nb, int *e)
{
	char	*tmp;

	tmp = ft_strjoin("1", *nb);
	ft_strdel(nb);
	*nb = tmp;
	*e += 1;
}

void	adjust_exponent(char **nb, int i, int *e)
{
	while (i >= 0)
	{
		if ((*nb)[i] != '0' && (*nb)[i] != '.')
			return ;
		i--;
	}
	*e += 1;
}

void	remove_minus(char **nb)
{
	char *tmp;

	tmp = ft_strsub(*nb, 1, ft_strlen(*nb));
	ft_strdel(nb);
	*nb = tmp;
}
