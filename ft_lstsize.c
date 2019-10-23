/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:02:06 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 12:03:22 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = lst->content_size;
	lst = lst->next;
	while (lst)
	{
		size = size + lst->content_size;
		lst = lst->next;
	}
	return (size);
}
