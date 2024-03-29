/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2021/07/29 18:05:45 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include "ft_printf.h"
# include "ft_bst.h"

# define BUFF_SIZE 4096
# define MAX_FD 4864

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_twlist
{
	void			*content;
	size_t			content_size;
	int8_t			end;
	struct s_twlist	*next;
	struct s_twlist	*prev;
}					t_twlist;

typedef struct		s_ldbl
{
	char			sign;
	uint64_t		sig;
	int				e;
	char			bit63;
	char			bit62;
}					t_ldbl;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memdup(const void *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *nbr, unsigned int base);
long long			ft_atoll(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_ishex(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_lstcount(t_list *lst);
char				*ft_strreplace(char *search, char *replace, char **subject);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void				*ft_lstjoin(const void *s1, const void *s2);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstapp(t_list **alst, t_list *new);
void				ft_strtoupper(char *str);
void				ft_strtolower(char *str);
void				ft_lsttoupper(t_list *elem);
void				ft_lsttolower(t_list *elem);
void				ft_lstprint(t_list *elem);
t_list				*ft_lstcapitalize(t_list *elem);
void				ft_strcapitalize(char *str);
void				*ft_lstfold(t_list **alst,
						void *(*f)(const void *, const void *));
void				*ft_lstpop(t_list **alst);
size_t				ft_lstsize(t_list *lst);
void				ft_lstfree(void *content, size_t content_size);
t_list				*ft_lstchr(t_list *lst, int c);
int					ft_lstcount(t_list *lst);
int					get_next_line(const int fd, char **line);
int					get_next_number(char **line, intmax_t *number);
char				*ft_strreplace(char *search, char *replace, char **subject);
void				ft_exiterror(char *err_msg, int exitcode, int fd);
char				*ft_dtoa(double dbl, int prec);
void				trim_dblstr(char **nb, int prec);
char				*ft_ldtoa(long double dbl, int prec);
char				*ft_dtoa_hex(double dbl, int prec, int upper);
char				*ft_ldtoa_hex(long double dbl, int prec, int upper);
char				*ft_ltoa(intmax_t n);
int					ft_max(int a, int b);
double				ft_dmax(double a, double b);
int					ft_min(int a, int b);
double				ft_dmin(double a, double b);
int					ft_putnchar(char c, int count);
char				*ft_strnjoin(int n, ...);
char				*ft_ultoa_base(uintmax_t n, int base, int upper);
long double			ft_pow(long double nb, int power);
double				ft_ceil(double x);
int					ft_abs(int a);
char				*ft_strtrimchr(char const *s, char c, char mode);
size_t				ft_nbrlen(intmax_t nb);
int					ft_numcmp(void *n1, void *n2);
int					ft_ctoi(char c);
char				ft_hexincr(char c, int upper);
void				ft_strrev(char *str);
char				*vlq_sum(char *nb1, char *nb2);
void				vlq_multiply_2(char **nb, int times);
void				ft_strarrdel(char ***aa);
void				vlq_divide_2(char **nb, int times);
void				parse_double(double dbl, char *sign, int *e, uint64_t *sig);
size_t				ft_dbllen(double dbl);
void				parse_ldouble(long double dbl, t_ldbl *ldbl);
char				*ldbl_special_cases(t_ldbl *ldbl);
char				*dbl_special_cases(char sign, int e, uint64_t sig);
void				round_ldbl_hex(char **nb, int i, t_ldbl *ldbl);
int					round_dbl_hex(char *nb, int i);
int					ft_printf(const char *format, ...);
t_twlist			*ft_twlstnew(void const *content, size_t content_size);
void				ft_twlstadd(t_twlist **alst, t_twlist *new);
void				ft_twlstapp(t_twlist **alst, t_twlist *new);
int					ft_twlstcount(t_twlist *lst);
t_twlist			*ft_twlstdetach(t_twlist **alst);
void				ft_twlstdelone(t_twlist **alst,
									void (*del)(void *, size_t));
void				ft_twlstdel(t_twlist **alst, void (*del)(void *, size_t));

#endif
