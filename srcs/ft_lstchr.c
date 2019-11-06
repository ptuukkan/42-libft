/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:30:45 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:32:24 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstchr(t_list *lst, int c)
{
	while (lst)
	{
		if (ft_strchr(lst->content, c))
			break ;
		lst = lst->next;
	}
	return (lst);
}
