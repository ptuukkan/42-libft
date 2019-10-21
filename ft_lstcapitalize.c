/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:51:28 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 11:51:29 by ptuukkan         ###   ########.fr       */
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
