/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstconnect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:02:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:02:58 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstconnect(t_twlist *lst)
{
	t_twlist	*tmp;

	tmp = lst;
	if (!tmp->next)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
	lst->prev = tmp;
}
