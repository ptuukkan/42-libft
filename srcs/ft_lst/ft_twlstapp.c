/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstapp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:01:09 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:19:08 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstapp(t_twlist **alst, t_twlist *new)
{
	t_twlist	*temp;

	if (new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		(*alst)->end = 1;
		return ;
	}
	temp = *alst;
	while (temp->end == 0)
		temp = temp->next;
	new->next = temp->next;
	new->end = 1;
	temp->next = new;
	temp->end = 0;
	new->prev = temp;
	if (new->next)
		new->next->prev = new;
}
