/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:45:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 11:45:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	uc;
	unsigned char	*str;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		str[i] = uc;
		n--;
		i++;
	}
	return (s);
}
