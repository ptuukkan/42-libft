/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:01:24 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:20:21 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcapitalize(t_list *elem)
{
	t_list	*lst;

	lst = ft_lstnew(elem->content, elem->content_size);
	if (lst == NULL)
		return (NULL);
	ft_strcapitalize((char *)lst->content);
	return (lst);
}
