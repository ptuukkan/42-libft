/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:49:48 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:13:42 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (n > 0 && *src != '\0')
	{
		dest[i] = *src;
		i++;
		src++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
