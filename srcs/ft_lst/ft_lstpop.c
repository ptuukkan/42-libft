/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:03:07 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:03:12 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop(t_list **alst)
{
	t_list	*temp;
	void	*content;

	temp = *alst;
	if (temp == NULL)
		return (NULL);
	content = temp->content;
	*alst = (*alst)->next;
	free(temp);
	return (content);
}
