/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:43:58 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 11:44:00 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	uc;

	src = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n > 0 && *src != uc)
	{
		src++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
		return (src);
}
