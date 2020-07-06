/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pad_zeroes(char **nb, int prec)
{
	size_t	len;
	size_t	newlen;
	char	*tmp;

	if (*nb == NULL)
		return (0);
	len = ft_strlen(*nb);
	if (len == 16 && prec <= 16)
		return (1);
	newlen = (size_t)ft_max(16, prec);
	if (!(tmp = ft_strnew(newlen)))
		return (0);
	ft_memset(tmp, '0', newlen);
	ft_strncpy(tmp + (16 - len), *nb, len);
	ft_strdel(nb);
	*nb = tmp;
	return (1);
}

static void	trim_hex(char **nb, int prec, t_ldbl *ldbl)
{
	char	*tmp;

	if (nb == NULL)
		return ;
	if (prec == -1)
	{
		tmp = ft_strtrimchr(*nb, '0', 1);
		ft_strdel(nb);
		*nb = tmp;
	}
	else
	{
		if (ft_ctoi((*nb)[prec + 1]) >= 8)
		{
			(*nb)[prec + 1] = '\0';
			round_ldbl_hex(nb, prec, ldbl);
			return ;
		}
		(*nb)[prec + 1] = '\0';
	}
}

static char	*get_exp(t_ldbl *ldbl)
{
	char	*e_str;
	char	*tmp;

	if (ldbl->e == 0 && ldbl->sig == 0)
		return (ft_strdup("p+0"));
	tmp = ft_itoa(ldbl->e -= 16386);
	if (ldbl->e >= 0)
		e_str = ft_strjoin("p+", tmp);
	else
		e_str = ft_strjoin("p", tmp);
	ft_strdel(&tmp);
	return (e_str);
}

static char	*double_to_hex(char *nb, int prec, t_ldbl *ldbl)
{
	char	*tmp;
	char	*result;
	int		i;

	i = 0;
	if (nb == NULL || !pad_zeroes(&nb, prec))
		return (NULL);
	if (!(tmp = ft_strnew(3)))
		return (NULL);
	trim_hex(&nb, prec, ldbl);
	if (ldbl->sign)
		tmp[i++] = '-';
	tmp[i++] = *nb;
	if (nb[0] != '\0' && nb[1] != '\0')
		tmp[i++] = '.';
	result = ft_strjoin(tmp, nb + 1);
	ft_strdel(&tmp);
	ft_strdel(&nb);
	return (result);
}

char		*ft_ldtoa_hex(long double dbl, int prec, int upper)
{
	t_ldbl	ldbl;
	char	*nb;
	char	*exp_str;
	char	*tmp;

	parse_ldouble(dbl, &ldbl);
	if ((nb = ldbl_special_cases(&ldbl)))
		return (nb);
	tmp = double_to_hex(ft_ultoa_base(ldbl.sig, 16, upper), prec, &ldbl);
	exp_str = get_exp(&ldbl);
	if (!(nb = ft_strjoin(tmp, exp_str)))
		return (NULL);
	ft_strdel(&tmp);
	ft_strdel(&exp_str);
	if (upper)
		ft_strtoupper(nb);
	return (nb);
}
