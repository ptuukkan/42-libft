/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *str)
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

char		*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		neg;

	if (!(result = ft_strnew(sizeof(char) * 11)))
		return (NULL);
	if (n == -2147483648)
		return (result = ft_strcpy(result, "-2147483648"));
	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	while (n > 9)
	{
		result[i++] = (n % 10) + 48;
		n /= 10;
	}
	result[i++] = (n + 48);
	if (neg == 1)
		result[i] = '-';
	ft_strrev(result);
	return (result);
}
