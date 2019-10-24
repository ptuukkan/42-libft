/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:01:33 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:18:34 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (*alst == NULL)
		return ;
	while (*alst != NULL)
	{
		if ((*alst)->content != NULL)
			(*del)((*alst)->content, (*alst)->content_size);
		temp = *alst;
		*alst = (*alst)->next;
		free(temp);
		temp = NULL;
	}
}
