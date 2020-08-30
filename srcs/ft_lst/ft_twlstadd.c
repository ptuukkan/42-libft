/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:00:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:18:58 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstadd(t_twlist **alst, t_twlist *new)
{
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
	else
	{
		new->next = *alst;
		new->prev = (*alst)->prev;
		(*alst)->prev->next = new;
		(*alst)->prev = new;
		*alst = new;
	}
}
