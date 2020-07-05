/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_binary(char *nb, int len, t_flags *flags)
{
	flags->field -= ft_max(flags->precision, len / 8);
	flags->precision -= len / 8;
	if (flags->leftadj == 0)
	{
		while (flags->field-- > 0)
		{
			flags->printed += ft_putnchar(flags->pad, 8);
			flags->printed += ft_putnchar(' ', 1);
		}
	}
	while (flags->precision-- > 0)
	{
		flags->printed += ft_putnchar('0', 8);
		flags->printed += ft_putnchar(' ', 1);
	}
	flags->printed += write(1, nb, len);
	if (flags->leftadj)
		while (flags->field-- > 0)
			flags->printed += ft_putnchar(flags->pad, 9);
}

static char	*split_binary(char **str, size_t len)
{
	size_t	newlen;
	int		i;
	int		n;
	char	*result;

	newlen = len + (int)ft_ceil(len / 8.0) - 1;
	if (!(result = ft_strnew(newlen)))
		return (NULL);
	i = 0;
	n = 0;
	while (str[0][n] != '\0')
	{
		if (n > 0 && len - n > 0 && (len - n) % 8 == 0)
			result[i++] = ' ';
		result[i++] = str[0][n++];
	}
	ft_strdel(str);
	return (result);
}

static char	*pad_binary_string(char **str, int len, t_flags *flags)
{
	int		num_of_pads;
	char	*pad;
	char	*result;

	if (len % 8 == 0 || ft_max(flags->precision, flags->field) <= len / 8 ||
	(flags->leftadj && flags->precision <= len / 8))
		return (*str);
	num_of_pads = 8 - (len % 8);
	if (!(pad = ft_strnew(num_of_pads)))
		return (NULL);
	if (flags->precision > len / 8)
		ft_memset(pad, '0', num_of_pads);
	else
		ft_memset(pad, flags->pad, num_of_pads);
	if (!(result = ft_strjoin(pad, *str)))
		return (NULL);
	ft_strdel(&pad);
	ft_strdel(str);
	return (result);
}

void		convert_b(va_list *ap, t_flags *flags)
{
	uintmax_t	u;
	char		*nb;
	size_t		len;

	adjust_flags(flags, flags->spec);
	u = get_u(ap, flags);
	nb = NULL;
	if (!(nb = ft_ultoa_base(u, 2, 0)))
		return ;
	len = ft_strlen(nb);
	if (flags->altform)
	{
		if (!(nb = split_binary(&nb, len)))
			return ;
		if (!(nb = pad_binary_string(&nb, len, flags)))
			return ;
		print_binary(nb, ft_strlen(nb), flags);
	}
	else
		print_u(nb, len, flags);
	ft_strdel(&nb);
}
