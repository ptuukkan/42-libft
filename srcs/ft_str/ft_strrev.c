/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:42 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/18 14:11:37 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int		i;
	int		n;
	char	temp;

	i = 0;
	n = (int)ft_strlen(str) - 1;
	while (n > i)
	{
		temp = str[n];
		str[n] = str[i];
		str[i] = temp;
		n--;
		i++;
	}
}
