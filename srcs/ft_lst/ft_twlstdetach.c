/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstdetach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:02:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:02:58 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_twlist	*ft_twlstdetach(t_twlist **alst)
{
	int			size;
	t_twlist	*lst;

	lst = *alst;
	size = ft_twlstcount(lst);
	*alst = (*alst)->next;
	if (size != 1 && !lst->prev)
		return (NULL);
	if (size == 2)
	{
		lst->prev->next = NULL;
		lst->prev->prev = NULL;
		lst->prev->end = 1;
	}
	else if (size > 2)
	{
		if (lst->end)
			lst->prev->end = 1;
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
	}
	lst->end = 0;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}
