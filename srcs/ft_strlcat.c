/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:48:22 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 12:51:35 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	ret;

	if ((ft_strlen(dst) + 1) > dstsize)
		return (ft_strlen(src) + dstsize);
	ret = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i] != '\0' && dstsize-- > 0)
		i++;
	while (dstsize > 1 && *src != '\0')
	{
		dst[i] = *src;
		i++;
		src++;
		dstsize--;
	}
	dst[i] = '\0';
	return (ret);
}
