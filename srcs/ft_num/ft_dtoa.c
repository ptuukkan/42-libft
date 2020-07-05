/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*dbl_special_cases(char sign, int e, uint64_t sig)
{
	char	*result;

	result = NULL;
	if (e == 2047 && sig == 0 && sign == 1)
		result = ft_strdup("-inf");
	else if (e == 2047 && sig == 0 && sign == 0)
		result = ft_strdup("inf");
	else if (e == 2047 && sig != 0)
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
	if (len == 13)
		return (1);
	newlen = 13;
	if (!(tmp = ft_strnew(newlen)))
		return (0);
	ft_memset(tmp, '0', newlen);
	ft_strncpy(tmp + (13 - len), *nb, len);
	ft_strdel(nb);
	*nb = tmp;
	return (1);
}

static char	*mantissa_to_dec(char *nb, uint64_t sig, int e, int i)
{
	int		n;
	char	*tmp;
	char	*tmp2;
	char	*result;

	n = -1;
	result = NULL;
	if (e == 0 && sig == 0)
		return (nb);
	if (!(tmp = ft_strdup("1.0")))
		return (NULL);
	if (e == 0 && sig != 0)
		tmp[0] = '0';
	if (!pad_zeroes(&nb))
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

char		*ft_dtoa(double dbl, int prec)
{
	char		sign;
	int			e;
	uint64_t	sig;
	char		*nb;
	char		*tmp;

	parse_double(dbl, &sign, &e, &sig);
	if ((nb = dbl_special_cases(sign, e, sig)))
		return (nb);
	nb = mantissa_to_dec(ft_ultoa_base(sig, 16, 0), sig, e, 0);
	e -= 1023;
	if (e > 0)
		vlq_multiply_2(&nb, e);
	else
		vlq_divide_2(&nb, -e);
	trim_dblstr(&nb, prec);
	if (sign)
	{
		tmp = ft_strjoin("-", nb);
		ft_strdel(&nb);
		nb = tmp;
	}
	return (nb);
}
