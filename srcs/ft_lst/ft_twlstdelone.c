/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:01:40 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:01:42 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstdelone(t_twlist **alst, void (*del)(void *, size_t))
{
	t_twlist	*tmp;

	if (*alst != NULL)
	{
		tmp = *alst;
		if (tmp->end)
			tmp->prev->end = 1;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		if (tmp->content != NULL)
			(*del)(tmp->content, tmp->content_size);
		free(tmp);
		tmp = NULL;
	}
}
