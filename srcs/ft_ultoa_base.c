/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ultoa_base(uint64_t n, int base, int upper)
{
	char		*result;
	int			i;
	uint64_t	d;
	char		*radix;

	i = 1;
	d = n;
	while (d /= base)
		i++;
	if (!(result = ft_strnew(sizeof(char) * i)))
		return (NULL);
	if (upper == 1 || upper == 'X')
		radix = ft_strdup("0123456789ABCDEF");
	else
		radix = ft_strdup("0123456789abcdef");
	while (i-- > 0)
	{
		result[i] = radix[n % base];
		n /= base;
	}
	free(radix);
	return (result);
}
