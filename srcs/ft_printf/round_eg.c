/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_eg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:00:52 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/02/26 13:00:54 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	bankers_round(char *nb, int i)
{
	while (nb[i] != '\0')
	{
		if (nb[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static int	previous_value(char *nb, int i)
{
	if (i <= 0)
		return (0);
	if (nb[i - 1] == '.')
	{
		if (i - 2 >= 0)
			return (ft_ctoi(nb[i - 2]));
		else
			return (0);
	}
	return (ft_ctoi(nb[i - 1]));
}

void		round_eformat(char **nb, int i, int *e)
{
	if ((*nb)[i] == '.')
		i++;
	if ((*nb)[i] == '\0' || ft_ctoi((*nb)[i]) < 5)
		return ;
	if (ft_ctoi((*nb)[i]) == 5 && (previous_value(*nb, i) & 1) == 0 &&
		bankers_round(*nb, i + 1))
		return ;
	while (i-- > 0)
	{
		if ((*nb)[i] == '.')
			i--;
		(*nb)[i] = (ft_ctoi((*nb)[i]) + 1) % 10 + '0';
		if ((*nb)[i] != '0')
			break ;
	}
	if (i < 0)
		handle_rounding_overflow(nb, e);
}

void		round_gformat(char **nb, int i, int *e)
{
	if ((*nb)[i] == '.')
		i++;
	if ((*nb)[i] == '\0' || ft_ctoi((*nb)[i]) < 5)
		return ;
	if (ft_ctoi((*nb)[i]) == 5 && (previous_value(*nb, i) & 1) == 0 &&
		bankers_round(*nb, i + 1))
		return ;
	while (i-- > 0)
	{
		if ((*nb)[i] == '.')
			i--;
		(*nb)[i] = (ft_ctoi((*nb)[i]) + 1) % 10 + '0';
		if ((*nb)[i] == '1' && i != 0 && (*nb)[i - 1] == '0')
			adjust_exponent(nb, i - 1, e);
		if ((*nb)[i] != '0')
			break ;
	}
	if (i < 0)
		handle_rounding_overflow(nb, e);
}
