/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:41:06 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 12:38:44 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	while (n > 0 && s[i] != (char)c)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	if (s[i] == (char)c && n > 0)
	{
		d[i] = s[i];
		return (&d[i + 1]);
	}
	return (NULL);
}
