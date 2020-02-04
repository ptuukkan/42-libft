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

static char	*ft_dtoa_fraction(long double dbl, int prec)
{
	char				*nb;
	int					i;

	i = 0;
	if (!(nb = ft_strnew(prec)))
		return (NULL);
	if (dbl == 0.0)
		ft_memset(nb, 48, prec);
	while (prec-- > 0)
	{
		dbl *= 10;
		nb[i++] = 48 + (int)(dbl);
		dbl -= (int)dbl;
	}
	return (nb);
}

static char	*ft_dtoa_zeroprec(long double dbl, int altform)
{
	uint64_t	u;
	char		*nb;
	char		*tmp;

	u = (uint64_t)dbl + 0.5;
	if (altform)
	{
		tmp = ft_ultoa_base(u, 10, 0);
		if (!(nb = ft_strjoin(tmp, ".")))
			return (NULL);
		ft_strdel(&tmp);
		return (nb);
	}
	else
		return (ft_ultoa_base(u, 10, 0));
}

char		*ft_dtoa(long double dbl, int prec, int altform)
{
	uint64_t	u;
	char		*nb;
	char		*fraction;
	char		*result;

	dbl = dbl + (0.5 / ft_pow(10, 10, prec));
	if (prec == 0)
		return (ft_dtoa_zeroprec(dbl, altform));
	else
	{
		u = (uint64_t)dbl;
		if (!(nb = ft_ultoa_base(u, 10, 0)))
			return (NULL);
		dbl = dbl - u;
		if (!(fraction = ft_dtoa_fraction(dbl, prec)))
			return (NULL);
		if (!(result = ft_strnjoin(3, nb, ".", fraction)))
			return (NULL);
		ft_strdel(&fraction);
	}
	ft_strdel(&nb);
	return (result);
}
