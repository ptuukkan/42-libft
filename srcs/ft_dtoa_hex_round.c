/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_hex_round.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	round_dbl_hex(char *nb, int i)
{
	while (i >= 0)
	{
		nb[i] = ft_hexincr(nb[i], 0);
		if (nb[i] != '0')
			break ;
		i--;
	}
	if (i < 0)
		return (1);
	else
		return (0);
}
