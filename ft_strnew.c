/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:16 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 11:50:18 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;

	temp = (char *)malloc(size + 1);
	if (temp != NULL)
	{
		ft_bzero(temp, size + 1);
		return (temp);
	}
	return (NULL);
}
