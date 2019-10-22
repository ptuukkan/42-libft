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

void	*ft_lstfold(t_list *lst, void *(*f)(const void *, const void *))
{
	void	*result;

	if (lst == NULL)
		return (NULL);
	result = lst->content;
	lst = lst->next;
	while (lst != NULL)
	{
		result = (*f)(result, lst->content);
		lst = lst->next;
	}
	return (result);
}
