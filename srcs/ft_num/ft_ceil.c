/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:48:41 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/02/03 11:48:43 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_ceil(double x)
{
	if (x > INT64_MAX)
		return (x);
	else
		return ((int64_t)(x + 0.99999999999999997));
}