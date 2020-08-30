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
		(*alst)->next = *alst;
		(*alst)->prev = *alst;
		(*alst)->end = 1;
		return ;
	}
	temp = *alst;
	new->end = 1;
	temp->end = 0;
	temp->prev->end = 0;
	new->next = temp;
	new->prev = temp->prev;
	temp->prev->next = new;
	temp->prev = new;
}
