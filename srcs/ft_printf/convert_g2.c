/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_g2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:01:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/02/25 11:01:41 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_altform(char *nb, t_flags *flags)
{
	int	i;

	i = (int)ft_strlen(nb) - 1;
	if (flags->altform == 0)
	{
		while (nb[i] == '0')
			i--;
		if (nb[i] == '.')
			i--;
		nb[i + 1] = '\0';
	}
}

char		*convert_to_etype(char **nb, int e, t_flags *flags)
{
	char	*e_str;
	char	*result;
	int		i;
	int		n;

	if (!(result = ft_strnew(flags->precision + 1)))
		return (NULL);
	i = 0;
	n = 0;
	while ((*nb)[i] != '\0' && ft_ctoi((*nb)[i]) <= 0)
		i++;
	result[n++] = (*nb)[i++];
	result[n++] = '.';
	while (flags->precision-- > 1)
		result[n++] = (*nb)[i++];
	if (!(e_str = get_exp_str(e)))
		return (NULL);
	ft_strdel(nb);
	handle_altform(result, flags);
	*nb = ft_strjoin(result, e_str);
	ft_strdel(&result);
	ft_strdel(&e_str);
	return (*nb);
}

char		*convert_to_ftype(char **nb, t_flags *flags)
{
	char	*tmp;
	int		i;

	i = ft_strlen(*nb) - 1;
	if (flags->altform == 0)
	{
		while (i > 0 && (*nb)[i] == '0')
			i--;
		if ((*nb)[i] == '.')
			i--;
		(*nb)[i + 1] = '\0';
	}
	if (flags->altform && !ft_strchr(*nb, '.'))
	{
		tmp = ft_strjoin(*nb, ".");
		ft_strdel(nb);
		*nb = tmp;
	}
	return (*nb);
}

static void	get_start_and_dot(char *nb, int *dot, int *st, int prec)
{
	*st = 0;
	while (nb[*st] != '\0' && (nb[*st] == '0' || nb[*st] == '.'))
		(*st)++;
	if (nb[*st] == '\0')
		*st = 0;
	*dot = ft_strchr(nb, '.') - nb;
	if (*dot > *st && *dot < prec)
		*dot = 1;
	else
		*dot = 0;
}

void		trim_gformat(char **nb, size_t len, int prec, int *e)
{
	int		dot;
	char	*pad;
	char	*tmp;
	int		st;

	get_start_and_dot(*nb, &dot, &st, prec);
	if ((len - st) - dot < (size_t)prec)
	{
		if (!(pad = ft_strnew(prec - ((len - st) - dot))))
			return ;
		ft_memset(pad, '0', prec - ((len - st) - dot));
		tmp = ft_strjoin(*nb, pad);
		ft_strdel(nb);
		ft_strdel(&pad);
		*nb = tmp;
	}
	round_gformat(nb, st + prec + dot, e);
	(*nb)[st + prec + dot] = '\0';
	if ((*nb)[st + prec + dot - 1] == '.')
		(*nb)[st + prec + dot - 1] = '\0';
}
