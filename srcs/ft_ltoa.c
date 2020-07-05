/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa(intmax_t n)
{
	char		*result;
	size_t		i;
	int			sign;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	i = ft_nbrlen(n);
	sign = (n < 0);
	if (!(result = ft_strnew(sizeof(char) * i + sign)))
		return (NULL);
	if (sign)
	{
		n = -n;
		result[0] = '-';
	}
	while (i-- > 0)
	{
		result[i + sign] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}
