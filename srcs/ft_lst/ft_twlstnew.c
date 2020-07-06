/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:02:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:02:58 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_twlist	*ft_twlstnew(void const *content, size_t content_size)
{
	t_twlist	*newlst;

	newlst = (t_twlist *)malloc(sizeof(t_twlist));
	if (newlst == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		newlst->content = ft_memalloc(content_size);
		if (newlst->content == NULL)
			return (NULL);
		newlst->content = ft_memcpy(newlst->content, content, content_size);
		newlst->content_size = content_size;
	}
	newlst->next = NULL;
	newlst->prev = NULL;
	newlst->end = 0;
	return (newlst);
}
