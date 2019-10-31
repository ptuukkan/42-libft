/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:38:15 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 14:59:17 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_continue(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '\e' || c == '\200')
		return (0);
	if (c < 33 || c == '+')
		return (2);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		neg;

	i = 0;
	result = 0;
	neg = 1;
	while (ft_continue(str[i]) == 2 && str[i] != '\0')
	{
		if (str[i] == '+' && ft_continue(str[i + 1]) != 1)
			return (0);
		i++;
	}
	if (str[i] == '-')
	{
		i++;
		neg = -1;
	}
	while (ft_continue(str[i]) == 1)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (neg * result);
}
