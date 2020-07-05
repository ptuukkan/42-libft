/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:10:12 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/31 18:10:14 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define HH 1
# define H 2
# define L 3
# define LL 4
# define UL 5
# define J 6
# define Z 7

typedef struct	s_flags
{
	char		spec;
	char		altform;
	char		pad;
	char		leftadj;
	char		blank;
	char		sign;
	char		signch;
	int			field;
	char		field_set;
	int			precision;
	char		precision_set;
	int			printed;
	char		length;
	char		zero;
}				t_flags;

typedef struct	s_conv
{
	const char	format;
	void		(*f)(va_list *, t_flags *);
}				t_conv;

const char		*read_format(va_list *ap, const char *format, t_flags *flags);
uintmax_t		get_u(va_list *ap, t_flags *flags);
intmax_t		get_d(va_list *ap, t_flags *flags);
double			get_f(va_list *ap, t_flags *flags);
long double		get_lf(va_list *ap, t_flags *flags);
char			*get_exp_str(int e);
void			adjust_flags(t_flags *flags, char spec);
void			adjust_flags2(t_flags *flags, char spec);
void			convert_double(va_list *ap, t_flags *flags);
int				special_cases(int e, uint64_t sig, t_flags *flags);
void			convert_c(va_list *ap, t_flags *flags);
void			convert_s(va_list *ap, t_flags *flags);
void			convert_d(va_list *ap, t_flags *flags);
void			convert_o(va_list *ap, t_flags *flags);
void			convert_u(va_list *ap, t_flags *flags);
void			convert_b(va_list *ap, t_flags *flags);
void			convert_p(va_list *ap, t_flags *flags);
void			convert_x(va_list *ap, t_flags *flags);
void			convert_f(double dbl, t_flags *flags);
void			convert_lf(long double dbl, t_flags *flags);
void			convert_a(double dbl, t_flags *flags);
void			convert_la(long double dbl, t_flags *flags);
void			convert_g(double dbl, t_flags *flags);
void			convert_lg(long double dbl, t_flags *flags);
void			convert_e(double dbl, t_flags *flags);
void			convert_le(long double dbl, t_flags *flags);
void			convert_perc(va_list *ap, t_flags *flags);
void			print_f(char *nb, int len, t_flags *flags);
void			print_u(char *nb, int len, t_flags *flags);
void			print_special(char *str, int len, t_flags *flags);
int				get_dbl_exponent(char *dblstr);
void			round_eformat(char **nb, int i, int *e);
void			round_gformat(char **nb, int i, int *e);
void			trim_gformat(char **nb, size_t len, int prec, int *e);
char			*convert_to_etype(char **nb, int e, t_flags *flags);
char			*convert_to_eformat(char **nb, int prec, int *e);
char			*convert_to_ftype(char **nb, t_flags *flags);
void			handle_rounding_overflow(char **nb, int *e);
void			adjust_exponent(char **nb, int i, int *e);
void			remove_minus(char **nb);

#endif
