/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:11:56 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:12:01 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_exp_str(int e)
{
	char	*result;
	char	*tmp;

	if (e == 0)
		return (ft_strdup("e+00"));
	if (!(tmp = ft_itoa(e)))
		return (NULL);
	if (e > 9)
		result = ft_strjoin("e+", tmp);
	else if (e < -9)
		result = ft_strjoin("e", tmp);
	else if (e > 0)
		result = ft_strjoin("e+0", tmp);
	else
		result = ft_strjoin("e-0", tmp + 1);
	ft_strdel(&tmp);
	return (result);
}

int		get_dbl_exponent(char *dblstr)
{
	int		e;
	int		i;
	char	*dot;
	char	*digit;

	dot = ft_strchr(dblstr, '.');
	if (dot == NULL)
		return (ft_strlen(dblstr) - 1);
	i = 0;
	while (dblstr[i] != '\0' && ft_ctoi(dblstr[i]) <= 0)
		i++;
	digit = &dblstr[i];
	e = dot - digit;
	if (e > 0)
		e--;
	if (*digit == '\0')
		e = 0;
	return (e);
}

void	print_special(char *str, int len, t_flags *flags)
{
	if (ft_strcmp(str, "nan") == 0 || ft_strcmp(str, "NAN") == 0)
	{
		flags->sign = 0;
		flags->blank = 0;
	}
	flags->field -= len;
	if ((flags->blank && flags->signch != '-') ||
		(flags->sign == 1 && flags->signch == '+'))
		flags->field--;
	if (flags->leftadj == 0)
	{
		flags->printed += ft_putnchar(' ', flags->field);
	}
	if ((flags->blank && flags->signch != '-') ||
		(flags->sign == 1 && flags->signch == '+'))
		flags->printed += write(1, &flags->signch, 1);
	flags->printed += write(1, str, len);
	if (flags->leftadj == 1)
	{
		flags->printed += ft_putnchar(' ', flags->field);
	}
}

void	convert_double(va_list *ap, t_flags *flags)
{
	adjust_flags(flags, flags->spec);
	if (flags->spec == 'f' && flags->length == UL)
		return (convert_lf(get_lf(ap, flags), flags));
	if (flags->spec == 'f' && flags->length != UL)
		return (convert_f(get_f(ap, flags), flags));
	if ((flags->spec == 'e' || flags->spec == 'E') && flags->length == UL)
		return (convert_le(get_lf(ap, flags), flags));
	if ((flags->spec == 'e' || flags->spec == 'E') && flags->length != UL)
		return (convert_e(get_f(ap, flags), flags));
	if ((flags->spec == 'g' || flags->spec == 'G') && flags->length == UL)
		return (convert_lg(get_lf(ap, flags), flags));
	if ((flags->spec == 'g' || flags->spec == 'G') && flags->length != UL)
		return (convert_g(get_f(ap, flags), flags));
	if ((flags->spec == 'a' || flags->spec == 'A') && flags->length == UL)
		return (convert_la(get_lf(ap, flags), flags));
	if ((flags->spec == 'a' || flags->spec == 'A') && flags->length != UL)
		return (convert_a(get_f(ap, flags), flags));
}
