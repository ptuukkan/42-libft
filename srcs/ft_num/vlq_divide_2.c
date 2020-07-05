/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlq_divide_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*vlq_divide(char *nb)
{
	char	*result;
	int		i;
	double	d;
	double	rem;

	i = 0;
	rem = 0;
	result = ft_strnew(ft_strlen(nb) + 1);
	if (nb == NULL || result == NULL)
		return (NULL);
	while (nb[i] != '\0')
	{
		if (nb[i] == '.')
			result[i++] = '.';
		d = ft_ctoi(nb[i]) / 2.0;
		result[i] = (int)d + rem + '0';
		rem = (d - (int)d) * 10;
		i++;
	}
	if (rem)
		result[i] = rem + '0';
	return (result);
}

static void	add_decimal_point(char **nb)
{
	char	*s;

	s = ft_strjoin(*nb, ".0");
	ft_strdel(nb);
	*nb = s;
}

void		vlq_divide_2(char **nb, int times)
{
	char	*tmp;

	tmp = NULL;
	if (!ft_strchr(*nb, '.'))
		add_decimal_point(nb);
	while (times > 0)
	{
		tmp = vlq_divide(*nb);
		ft_strdel(nb);
		*nb = tmp;
		times--;
	}
}
