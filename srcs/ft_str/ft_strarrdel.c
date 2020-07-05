/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:47:06 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 11:47:08 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrdel(char ***aa)
{
	int	i;

	i = 0;
	if (aa == NULL)
		return ;
	while ((*aa)[i] != NULL)
		i++;
	while (i > 0)
	{
		ft_strdel(&(*aa)[i]);
		i--;
	}
	if ((*aa)[0] != NULL)
		ft_strdel(&(*aa)[0]);
	if (*aa)
		free(*aa);
}
