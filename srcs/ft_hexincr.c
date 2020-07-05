/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexincr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_hexincr(char c, int upper)
{
	if (c >= '0' && c <= '8')
		return (c + 1);
	if (c == '9')
		return (97 - (upper * 32));
	if (c >= 'a' && c <= 'e')
		return (c + 1);
	if (c >= 'A' && c <= 'E')
		return (c + 1);
	if (c == 'F' || c == 'f')
		return ('0');
	return (c);
}
