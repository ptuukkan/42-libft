/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:01:09 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:19:08 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_twlstcount(t_twlist *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		if (lst->end == 1)
			break ;
		lst = lst->next; 
	}
	return (i);
}
