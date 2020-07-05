/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ldbl_special_cases(t_ldbl *ldbl)
{
	char		*result;
	uint64_t	bits;

	bits = (ldbl->sig & 0x3FFFFFFFFFFFFFFF);
	result = NULL;
	if (ldbl->e == 32767 && ldbl->sign == 1 && ldbl->bit62 == 0 && bits == 0)
		result = ft_strdup("-inf");
	else if (ldbl->e == 32767 && ldbl->sign == 0 && ldbl->bit62 == 0
			&& bits == 0)
		result = ft_strdup("inf");
	else if (ldbl->e == 32767 && ldbl->bit62 == 0 && bits != 0)
		result = ft_strdup("nan");
	return (result);
}

static char	*dbl_to_str(double dbl)
{
	char	*result;
	int		i;

	i = 2;
	result = ft_strnew((size_t)ft_max(ft_dbllen(dbl) + 1, 3));
	result[0] = (int)dbl + '0';
	result[1] = '.';
	if (dbl == 0.0)
	{
		result[2] = '0';
		return (result);
	}
	dbl -= (int)dbl;
	dbl *= 10;
	while (dbl != 0.0)
	{
		result[i++] = (int)dbl + '0';
		dbl -= (int)dbl;
		dbl *= 10;
	}
	return (result);
}

static int	pad_zeroes(char **nb)
{
	size_t	len;
	size_t	newlen;
	char	*tmp;

	if (*nb == NULL)
		return (0);
	len = ft_strlen(*nb);
	if (len == 16)
		return (1);
	newlen = 16;
	if (!(tmp = ft_strnew(newlen)))
		return (0);
	ft_memset(tmp, '0', newlen);
	ft_strncpy(tmp + (16 - len), *nb, len);
	ft_strdel(nb);
	*nb = tmp;
	return (1);
}

static char	*mantissa_to_dec(char *nb, t_ldbl *ldbl)
{
	int		n;
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*result;

	n = 0;
	i = 0;
	result = NULL;
	if (ldbl->e == 0 && ldbl->sig == 0)
		return (nb);
	if (!pad_zeroes(&nb))
		return (NULL);
	if (!(tmp = ft_strdup("0.0")))
		return (NULL);
	while (nb[i] != '\0')
	{
		tmp2 = dbl_to_str(ft_ctoi(nb[i++]) * ft_pow(16, n--));
		result = vlq_sum(tmp, tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		tmp = result;
	}
	ft_strdel(&nb);
	return (result);
}

char		*ft_ldtoa(long double dbl, int prec)
{
	t_ldbl	ldbl;
	char	*nb;
	char	*tmp;

	parse_ldouble(dbl, &ldbl);
	if (ldbl.sign)
		dbl = -dbl;
	if ((nb = ldbl_special_cases(&ldbl)))
		return (nb);
	nb = mantissa_to_dec(ft_ultoa_base(ldbl.sig, 16, 0), &ldbl);
	ldbl.e -= 16386;
	if (ldbl.e > 0)
		vlq_multiply_2(&nb, ldbl.e);
	else
		vlq_divide_2(&nb, -ldbl.e);
	trim_dblstr(&nb, prec);
	if (ldbl.sign)
	{
		tmp = ft_strjoin("-", nb);
		ft_strdel(&nb);
		nb = tmp;
	}
	return (nb);
}
