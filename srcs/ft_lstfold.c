/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:01:47 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:01:49 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list **alst, void *(*f)(const void *, const void *))
{
	void	*result;
	void	*temp;
	t_list	*lst;

	lst = *alst;
	if (lst == NULL)
		return (NULL);
	if (!(result = ft_memdup(lst->content, lst->content_size)))
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		temp = result;
		if (!(result = (*f)(result, lst->content)))
			return (NULL);
		ft_memdel(&temp);
		lst = lst->next;
	}
	ft_lstdel(alst, &ft_lstfree);
	return (result);
}
