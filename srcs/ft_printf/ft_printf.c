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

t_conv	g_convtab[] =
{
	{'c', &convert_c},
	{'s', &convert_s},
	{'d', &convert_d},
	{'i', &convert_d},
	{'p', &convert_p},
	{'o', &convert_o},
	{'u', &convert_u},
	{'x', &convert_x},
	{'X', &convert_x},
	{'f', &convert_double},
	{'e', &convert_double},
	{'E', &convert_double},
	{'g', &convert_double},
	{'G', &convert_double},
	{'b', &convert_b},
	{'a', &convert_double},
	{'A', &convert_double},
	{'%', &convert_perc},
	{'\0', NULL}
};

static void	init_flagstruct(t_flags *flags)
{
	flags->altform = 0;
	flags->blank = 0;
	flags->field = 0;
	flags->field_set = 0;
	flags->leftadj = 0;
	flags->length = 0;
	flags->precision = 0;
	flags->precision_set = 0;
	flags->sign = 0;
	flags->signch = ' ';
	flags->pad = ' ';
	flags->zero = 0;
	flags->spec = 0;
}

const char	*convert(va_list *ap, const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	format = read_format(ap, format, flags);
	while (g_convtab[i].format != '\0')
	{
		if (*format == g_convtab[i].format)
		{
			flags->spec = *format;
			g_convtab[i].f(ap, flags);
			return (format + 1);
		}
		i++;
	}
	return (format);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	flags;

	va_start(ap, format);
	flags.printed = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			init_flagstruct(&flags);
			format++;
			if (*format == '\0')
				return (0);
			format = convert(&ap, format, &flags);
		}
		else
		{
			flags.printed += ft_putnchar(*format, 1);
			format++;
		}
	}
	va_end(ap);
	return (flags.printed);
}
