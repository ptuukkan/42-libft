/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_e2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:04:09 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/02/25 11:04:11 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	add_decimal_point(char **nb, size_t len)
{
	char	*tmp;
	int		i;
	int		n;

	if (!(tmp = ft_strnew(len + 1)))
		return ;
	i = 0;
	n = 0;
	while ((*nb)[n] != '\0')
	{
		if (i == 1)
			tmp[i++] = '.';
		else if ((*nb)[n] == '.')
			n++;
		else
		{
			tmp[i++] = (*nb)[n++];
		}
	}
	ft_strdel(nb);
	*nb = tmp;
}

static void	get_dot(char *nb, int *dot, int prec)
{
	char	*dot_ptr;

	dot_ptr = ft_strchr(nb, '.');
	if (dot_ptr == NULL)
		*dot = 0;
	else
	{
		if ((dot_ptr - nb) < prec)
			*dot = 1;
		else
			*dot = 0;
	}
}

static void	trim_eformat(char **nb, size_t len, int prec, int *e)
{
	int		dot;
	char	*pad;
	char	*tmp;

	get_dot(*nb, &dot, prec);
	if (len - dot < (size_t)prec)
	{
		if (!(pad = ft_strnew(prec - (len - (dot < prec)))))
			return ;
		ft_memset(pad, '0', prec - (len - (dot < prec)));
		tmp = ft_strjoin(*nb, pad);
		ft_strdel(nb);
		ft_strdel(&pad);
		*nb = tmp;
	}
	round_eformat(nb, prec + dot, e);
	(*nb)[prec + dot] = '\0';
	if ((*nb)[prec + dot - 1] == '.')
		(*nb)[prec + dot - 1] = '\0';
}

char		*convert_to_eformat(char **nb, int prec, int *e)
{
	int		i;
	char	*result;
	char	*exp_str;
	char	*tmp;

	i = 0;
	while ((*nb)[i] != '\0' && ((*nb)[i] == '0' || (*nb)[i] == '.'))
		i++;
	if ((*nb)[i] == '\0')
		i = 0;
	if (!(result = ft_strdup(*nb + i)))
		return (NULL);
	ft_strdel(nb);
	trim_eformat(&result, ft_strlen(result), prec + 1, e);
	add_decimal_point(&result, ft_strlen(result));
	if (!(exp_str = get_exp_str(*e)))
		return (NULL);
	tmp = result;
	result = ft_strjoin(tmp, exp_str);
	ft_strdel(&tmp);
	ft_strdel(&exp_str);
	return (result);
}
