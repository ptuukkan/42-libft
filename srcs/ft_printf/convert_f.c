/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_f(char *nb, int len, t_flags *flags)
{
	flags->field -= ft_max(flags->blank, flags->sign);
	flags->field -= len;
	if (flags->leftadj == 0)
	{
		if (flags->pad == '0' && (flags->sign == 1 || flags->blank == 1))
			flags->printed += ft_putnchar(flags->signch, 1);
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
	if (flags->pad == ' ' && (flags->sign == 1 || flags->blank == 1))
	{
		flags->printed += ft_putnchar(flags->signch, 1);
	}
	flags->printed += write(1, nb, len);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
}

static void	handle_altform(char **nb)
{
	char	*tmp;

	if (ft_strchr(*nb, '.'))
		return ;
	tmp = ft_strjoin(*nb, ".");
	ft_strdel(nb);
	*nb = tmp;
}

void		convert_f(double dbl, t_flags *flags)
{
	char		*nb;
	uint64_t	u;

	if (!(nb = ft_dtoa(dbl, flags->precision)))
		return ;
	if (ft_strstr(nb, "inf") || ft_strstr(nb, "nan"))
	{
		print_special(nb, ft_strlen(nb), flags);
		return ;
	}
	if (flags->altform)
		handle_altform(&nb);
	ft_memcpy(&u, &dbl, sizeof(double));
	if ((u >> 63) & 1)
		print_f(nb + 1, ft_strlen(nb + 1), flags);
	else
		print_f(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}

void		convert_lf(long double dbl, t_flags *flags)
{
	char		*nb;

	if (!(nb = ft_ldtoa(dbl, flags->precision)))
		return ;
	if (ft_strstr(nb, "inf") || ft_strstr(nb, "nan"))
	{
		print_special(nb, ft_strlen(nb), flags);
		return ;
	}
	if (flags->altform)
		handle_altform(&nb);
	if (nb[0] == '-')
		print_f(nb + 1, ft_strlen(nb + 1), flags);
	else
		print_f(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}
