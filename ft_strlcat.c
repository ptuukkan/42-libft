/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:48:22 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/18 14:49:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	ret;

	if ((ft_strlen(dst) + 1) > size)
		return (ft_strlen(src) + size);
	ret = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i] != '\0' && size-- > 0)
		i++;
	while (size > 1 && *src != '\0')
	{
		dst[i] = *src;
		i++;
		src++;
		size--;
	}
	dst[i] = '\0';
	return (ret);
}
