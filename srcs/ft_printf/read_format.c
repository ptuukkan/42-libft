/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:18:13 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 17:18:15 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*read_length(const char *format, t_flags *flags)
{
	if (format[0] == 'h' && format[1] == 'h')
		flags->length = HH;
	else if (format[0] == 'h')
		flags->length = H;
	else if (format[0] == 'l' && format[1] == 'l')
		flags->length = LL;
	else if (format[0] == 'l')
		flags->length = L;
	else if (format[0] == 'L')
		flags->length = UL;
	else if (format[0] == 'j')
		flags->length = J;
	else if (format[0] == 'z')
		flags->length = Z;
	if (flags->length == 0)
		return (format);
	if (flags->length == HH || flags->length == LL)
		return (format + 2);
	else if (flags->length != 0)
		return (format + 1);
	else
		return (format);
}

static const char	*read_flags(const char *format, t_flags *flags)
{
	while (ft_strchr("-+ #0", *format))
	{
		if (*format == '-')
			flags->leftadj = 1;
		if (*format == '+')
			flags->sign = 1;
		if (*format == ' ')
			flags->blank = 1;
		if (*format == '#')
			flags->altform = 1;
		if (*format == '0')
		{
			flags->pad = '0';
			flags->zero = 1;
		}
		format++;
	}
	if (flags->sign)
		flags->signch = '+';
	return (format);
}

static const char	*read_prec(va_list *ap, const char *format, t_flags *flags)
{
	if (*format == '.')
	{
		flags->precision_set = 1;
		format++;
		if (*format == '*')
		{
			flags->precision = va_arg(*ap, int);
			format++;
			if (flags->precision < 0)
				flags->precision_set = 0;
		}
		else
		{
			flags->precision = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
	}
	return (format);
}

static const char	*read_width(va_list *ap, const char *format, t_flags *flags)
{
	if (*format >= '1' && *format <= '9')
	{
		flags->field = ft_atoi(format);
		flags->field_set = 1;
		while (ft_isdigit(*format))
			format++;
	}
	else if (*format == '*')
	{
		flags->field = va_arg(*ap, int);
		flags->field_set = 1;
		if (flags->field < 0)
		{
			flags->field = -flags->field;
			flags->leftadj = 1;
		}
		format++;
	}
	return (format);
}

const char			*read_format(va_list *ap, const char *format,
									t_flags *flags)
{
	format = read_flags(format, flags);
	format = read_width(ap, format, flags);
	format = read_prec(ap, format, flags);
	format = read_length(format, flags);
	return (format);
}
