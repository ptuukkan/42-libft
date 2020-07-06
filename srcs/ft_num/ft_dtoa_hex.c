/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_hex.c                                      :+:      :+:    :+:   */
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
	if (len == 13 && prec <= 13)
		return (1);
	newlen = (size_t)ft_max(13, prec);
	if (!(tmp = ft_strnew(newlen)))
		return (0);
	ft_memset(tmp, '0', newlen);
	ft_strncpy(tmp + (13 - len), *nb, len);
	ft_strdel(nb);
	*nb = tmp;
	return (1);
}

static int	trim_hex(char **nb, int prec)
{
	char	*tmp;

	if (nb == NULL)
		return (0);
	if (prec == -1)
	{
		tmp = ft_strtrimchr(*nb, '0', 1);
		ft_strdel(nb);
		*nb = tmp;
	}
	else
	{
		if (ft_ctoi((*nb)[prec]) >= 8)
		{
			(*nb)[prec] = '\0';
			return (round_dbl_hex(*nb, prec - 1));
		}
		(*nb)[prec] = '\0';
	}
	return (0);
}

static char	*get_exp(int e, uint64_t sig)
{
	char	*e_str;
	char	*tmp;

	if (e == 0 && sig == 0)
		return (ft_strdup("p+0"));
	tmp = ft_itoa(e -= 1023);
	if (e >= 0)
		e_str = ft_strjoin("p+", tmp);
	else
		e_str = ft_strjoin("p", tmp);
	ft_strdel(&tmp);
	return (e_str);
}

static char	*double_to_hex(char *nb, int prec, char *e_str, char sign)
{
	char	*tmp;
	char	*result;
	int		i;

	i = 0;
	if (nb == NULL || !pad_zeroes(&nb, prec))
		return (NULL);
	if (!(tmp = ft_strnew(3)))
		return (NULL);
	if (sign)
		tmp[i++] = '-';
	tmp[i++] = '1' + trim_hex(&nb, prec);
	if (nb[0] != '\0')
		tmp[i++] = '.';
	result = ft_strnjoin(3, tmp, nb, e_str);
	ft_strdel(&tmp);
	ft_strdel(&nb);
	ft_strdel(&e_str);
	return (result);
}

char		*ft_dtoa_hex(double dbl, int prec, int upper)
{
	char		sign;
	int			e;
	uint64_t	sig;
	char		*nb;

	parse_double(dbl, &sign, &e, &sig);
	if ((nb = dbl_special_cases(sign, e, sig)))
		return (nb);
	nb = double_to_hex(ft_ultoa_base(sig, 16, upper), prec,
		get_exp(e, sig), sign);
	if (nb == NULL)
		return (NULL);
	if ((e == 0 && sig != 0) || dbl == 0.0)
		nb[(int)sign] = '0';
	if (upper)
		ft_strtoupper(nb);
	return (nb);
}
