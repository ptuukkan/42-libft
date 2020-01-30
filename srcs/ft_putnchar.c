/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:49:16 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 12:53:58 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnchar(char c, int count)
{
	int	ret;

	ret = 0;
	while (count-- > 0)
	{
		write(1, &c, 1);
		ret++;
	}
	return (ret);
}
