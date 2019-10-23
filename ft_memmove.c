/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:44:43 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 12:41:17 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;
	char	*temp;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	temp = (char *)malloc(sizeof(char) * len);
	if (temp)
	{
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
	}
	free(temp);
	return (dst);
}
