/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_double(double dbl, char *sign, int *e, uint64_t *sig)
{
	uint64_t	u;

	ft_memcpy(&u, &dbl, sizeof(double));
	u >>= 63;
	*sign = (char)u;
	ft_memcpy(&u, &dbl, sizeof(double));
	u <<= 1;
	u >>= 53;
	*e = (int)u;
	ft_memcpy(&u, &dbl, sizeof(double));
	*sig = (u & 0x000fffffffffffffL);
	if (*e == 0 && *sig != 0)
	{
		(*e)++;
		while (((*sig >> 52) & 1) == 0)
		{
			*sig <<= 1;
			(*e)--;
		}
	}
}

void	handle_subnormal(t_ldbl *ldbl)
{
	ldbl->e++;
	while (((ldbl->sig >> 63) & 1) == 0)
	{
		ldbl->sig <<= 1;
		ldbl->e--;
	}
}

void	parse_ldouble(long double dbl, t_ldbl *ldbl)
{
	unsigned char	*c;
	unsigned char	*tmp;
	uint64_t		sig;

	c = (unsigned char *)&dbl;
	ldbl->sign = (c[9] >> 7);
	if (!(tmp = (unsigned char *)ft_strnew(64)))
		return ;
	tmp = ft_memcpy(tmp, c + 8, 2);
	ldbl->e = (int)(*(unsigned short *)(tmp) & 0x7FFF);
	tmp = ft_memcpy(tmp, c, 8);
	sig = *(uint64_t *)(tmp);
	ldbl->bit63 = (sig >> 63) & 1;
	ldbl->bit62 = (sig >> 62) & 1;
	ldbl->sig = sig;
	free(tmp);
	if (ldbl->e == 0 && ldbl->bit63 == 0 && ldbl->sig != 0)
		handle_subnormal(ldbl);
	if (ldbl->e == 0 && ldbl->sig == 0)
		ldbl->e = 16386;
}
