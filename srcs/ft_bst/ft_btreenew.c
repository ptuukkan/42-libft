/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew(void const *content, size_t content_size)
{
	t_btree	*new;

	new = (t_btree *)ft_memalloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		if (!new->content)
			return (NULL);
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->right = NULL;
	new->left = NULL;
	return (new);
}
