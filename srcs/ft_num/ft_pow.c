/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_pow(long double nb, int power)
{
	long double	result;
	int			orig_power;

	orig_power = power;
	result = 1.0;
	power = ft_abs(power);
	if (power == 0)
		return (result);
	while (power-- > 0)
		result = result * nb;
	if (orig_power > 0)
		return (result);
	else
		return (1 / result);
}
