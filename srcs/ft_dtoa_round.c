/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bankers_round(char *nb, int i)
{
	while (nb[i] != '\0')
	{
		if (nb[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static int	previous_value(char *nb, int i)
{
	if (i <= 0)
		return (0);
	if (nb[i - 1] == '.')
	{
		if (i - 2 >= 0)
			return (ft_ctoi(nb[i - 2]));
		else
			return (0);
	}
	return (ft_ctoi(nb[i - 1]));
}

static void	round_dblstr(char **nb, int i)
{
	char	*over;
	char	*tmp;

	if ((*nb)[i] == '\0' || ft_ctoi((*nb)[i]) < 5)
		return ;
	if (ft_ctoi((*nb)[i]) == 5 && (previous_value(*nb, i) & 1) == 0 &&
		bankers_round(*nb, i + 1))
		return ;
	while (i-- >= 0)
	{
		if ((*nb)[i] == '.')
			i--;
		(*nb)[i] = (ft_ctoi((*nb)[i]) + 1) % 10 + '0';
		if ((*nb)[i] != '0')
			break ;
	}
	if (i < 0)
	{
		if (!(over = ft_strnew(1)))
			return ;
		over[0] = '1';
		tmp = ft_strjoin(over, *nb);
		ft_strdel(nb);
		*nb = tmp;
	}
}

static int	trim_lead_zero(char **nb, size_t len)
{
	char	*tmp;
	int		i;
	int		dot;

	i = 0;
	dot = ft_strchr(*nb, '.') - *nb;
	while ((*nb)[i] != '\0' && ((*nb)[i] == '0' || (*nb)[i] == '.'))
		i++;
	if (i < dot)
	{
		if (!(tmp = ft_strtrimchr(*nb, '0', 2)))
			return (0);
	}
	else
	{
		if (!(tmp = ft_strsub(*nb, dot - 1, len - (dot - 1))))
			return (0);
	}
	ft_strdel(nb);
	*nb = tmp;
	return (1);
}

void		trim_dblstr(char **nb, int prec)
{
	int		dot;
	char	*pad;
	char	*tmp;
	size_t	len;

	if (!trim_lead_zero(nb, ft_strlen(*nb)))
		return ;
	if (prec == -1)
		return ;
	len = ft_strlen(*nb);
	dot = ft_strchr(*nb, '.') - *nb;
	if ((len - 1 - dot) < (size_t)prec)
	{
		if (!(pad = ft_strnew(prec - (len - 1 - dot))))
			return ;
		ft_memset(pad, '0', prec - (len - 1 - dot));
		tmp = ft_strjoin(*nb, pad);
		ft_strdel(nb);
		ft_strdel(&pad);
		*nb = tmp;
	}
	round_dblstr(nb, dot + prec + 1);
	(*nb)[dot + prec + 1] = '\0';
	if ((*nb)[dot + prec] == '.')
		(*nb)[dot + prec] = '\0';
}
