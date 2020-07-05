/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:45:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 12:54:53 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	uc;
	unsigned char	*str;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)b;
	while (len > 0)
	{
		str[i] = uc;
		len--;
		i++;
	}
	return (b);
}
