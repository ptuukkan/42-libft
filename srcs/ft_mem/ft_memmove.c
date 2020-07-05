/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:44:43 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/24 12:10:34 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;
	char	*temp;

	if (dst == NULL || src == NULL)
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!(temp = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < len)
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		d[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
