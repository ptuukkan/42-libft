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

static int	d_special_cases(double dbl, char **nb)
{
	uint64_t	u;

	u = *(uint64_t *)&dbl;
	if (u == 0 || u > (uint64_t)9223372036854775807)
	{
		*nb = ft_strdup("0.0");
		return (1);
	}
	else if (u == (uint64_t)9218868437227405312)  // || u > (t_u64)18442240474082181119)
	{
		*nb = ft_strdup("inf");
		return (1);
	}
	else if (u == (uint64_t)9218868437227405313 || u == (uint64_t)9221120237041090561 ||
			u == (uint64_t)9223372036854775807)
	{
		*nb = ft_strdup("nan");
		return (1);
	}
	return (0);
}

static char	*ft_dtoa_fraction(double dbl, int prec)
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
		dbl = dbl - (int)(dbl);
	}
	return (nb);
}

char		*ft_dtoa(double dbl, int prec)
{
	uint64_t	u;
	char		*nb;
	char		*fraction;
	char		*result;

	if (d_special_cases(dbl, &nb))
		return (nb);
	if (prec == 0)
	{
		u = (uint64_t)dbl + 0.5;
		return (ft_ultoa_base(u, 10, 0));
	}
	else
		u = (uint64_t)dbl;
	if (!(nb = ft_ultoa_base(u, 10, 0)))
		return (NULL);
	dbl = dbl - u;
	if (!(fraction = ft_dtoa_fraction(dbl, prec)))
		return (NULL);
	if (!(result = ft_strnjoin(3 , nb, ".", fraction)))
		return (NULL);
	ft_strdel(&fraction);
	ft_strdel(&nb);
	return (result);
}
