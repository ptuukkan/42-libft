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

static t_twlist	*clean(t_twlist *lst)
{
	lst->end = 0;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_twlist		*ft_twlstdetach(t_twlist **alst)
{
	int			size;
	t_twlist	*lst;

	if (*alst == NULL)
		return (NULL);
	lst = *alst;
	size = ft_twlstcount(lst);
	if (size == 1)
		*alst = NULL;
	else
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
		if (lst->end)
			lst->prev->end = 1;
		*alst = lst->next;
	}
	return (clean(lst));
}
