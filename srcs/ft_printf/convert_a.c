/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_prefix(t_flags *flags)
{
	if (flags->spec == 'a')
		flags->printed += write(1, "0x", 2);
	else
		flags->printed += write(1, "0X", 2);
}

static void	print_a(char *nb, int len, t_flags *flags)
{
	flags->field -= ft_max(flags->blank, flags->sign);
	flags->field -= len;
	if (flags->leftadj == 0)
	{
		if (flags->pad == '0' && (flags->sign == 1 || flags->blank == 1))
			flags->printed += ft_putnchar(flags->signch, 1);
		if (flags->zero)
			print_prefix(flags);
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
	if (flags->pad == ' ' && (flags->sign == 1 || flags->blank == 1))
	{
		flags->printed += ft_putnchar(flags->signch, 1);
	}
	if (!flags->zero)
		print_prefix(flags);
	flags->printed += write(1, nb, len);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(flags->pad, flags->field);
	}
}

static void	handle_altform(char **nb, t_flags *flags)
{
	char	**tmp;
	char	*tmp2;
	char	split;

	if (ft_strchr(*nb, '.'))
		return ;
	split = 'p';
	if (flags->spec == 'A')
		split = 'P';
	tmp = ft_strsplit(*nb, split);
	tmp2 = ft_strnjoin(3, tmp[0], ".p", tmp[1]);
	if (tmp == NULL || tmp2 == NULL)
		return ;
	if (split == 'P')
		*ft_strchr(tmp2, 'p') = 'P';
	ft_strdel(nb);
	*nb = tmp2;
	ft_strdel(&tmp[1]);
	ft_strdel(&tmp[0]);
	free(tmp);
}

void		convert_a(double dbl, t_flags *flags)
{
	char		*nb;
	uint64_t	u;

	if (!(nb = ft_dtoa_hex(dbl, flags->precision, (flags->spec == 'A'))))
		return ;
	if (ft_strstr(nb, "inf") || ft_strstr(nb, "nan"))
	{
		print_special(nb, ft_strlen(nb), flags);
		return ;
	}
	if (flags->altform)
		handle_altform(&nb, flags);
	ft_memcpy(&u, &dbl, sizeof(double));
	if ((u >> 63) & 1)
		print_a(nb + 1, ft_strlen(nb + 1), flags);
	else
		print_a(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}

void		convert_la(long double dbl, t_flags *flags)
{
	char		*nb;

	if (!(nb = ft_ldtoa_hex(dbl, flags->precision, (flags->spec == 'A'))))
		return ;
	if (ft_strstr(nb, "inf") || ft_strstr(nb, "nan"))
	{
		print_special(nb, ft_strlen(nb), flags);
		return ;
	}
	if (flags->altform)
		handle_altform(&nb, flags);
	if (dbl < 0.0)
		print_a(nb + 1, ft_strlen(nb + 1), flags);
	else
		print_a(nb, ft_strlen(nb), flags);
	ft_strdel(&nb);
}
