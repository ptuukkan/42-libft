/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_hex_round.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:11:10 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/02/27 11:11:14 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	round_ldbl_hex(char **nb, int i, t_ldbl *ldbl)
{
	char	*tmp;

	tmp = NULL;
	while (i >= 0)
	{
		(*nb)[i] = ft_hexincr((*nb)[i], 0);
		if ((*nb)[i] != '0')
			break ;
		i--;
	}
	if (i == -1)
	{
		if (!(tmp = ft_strjoin("1", *nb)))
			return ;
		tmp[ft_strlen(tmp) - 1] = '\0';
		ldbl->e += 4;
		ft_strdel(nb);
		*nb = tmp;
	}
	return ;
}
