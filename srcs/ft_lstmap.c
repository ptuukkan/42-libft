/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:02:29 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:17:32 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*newlsthead;

	if (lst == NULL || (*f) == NULL)
		return (NULL);
	newlst = (*f)(lst);
	if (newlst == NULL)
		return (NULL);
	newlsthead = newlst;
	lst = lst->next;
	while (lst != NULL)
	{
		newlst->next = (*f)(lst);
		if (newlst->next == NULL)
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (newlsthead);
}
