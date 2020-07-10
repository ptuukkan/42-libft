/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avltnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avltree	*ft_avltnew(void const *content, size_t content_size)
{
	t_avltree	*newavlt;

	newavlt = (t_avltree *)ft_memalloc(sizeof(t_avltree));
	if (!newavlt)
		return (NULL);
	if (!content)
	{
		newavlt->content = NULL;
		newavlt->content_size = 0;
	}
	else
	{
		newavlt->content = ft_memalloc(content_size);
		if (!newavlt->content)
			return (NULL);
		newavlt->content = ft_memcpy(newavlt->content, content, content_size);
		newavlt->content_size = content_size;
	}
	newavlt->height = 1;
	newavlt->right = NULL;
	newavlt->left = NULL;
	return (newavlt);
}
