/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:31:50 by exam              #+#    #+#             */
/*   Updated: 2021/07/29 16:24:24 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_chartoint(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	else
		return (99);
}

int					ft_atoi_base(const char *nbr, unsigned int base)
{
	int	result;
	int	neg;

	if (base > 16 || base < 2 || nbr == 0)
		return (0);
	result = 0;
	neg = 1;
	if (nbr[0] == '-')
	{
		neg = -1;
		nbr++;
	}
	while (ft_chartoint(*nbr) < base)
	{
		result = base * result + ft_chartoint(*nbr);
		nbr++;
	}
	return (result * neg);
}
