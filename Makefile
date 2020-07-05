# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:36:17 by ptuukkan          #+#    #+#              #
#    Updated: 2020/07/05 12:40:28 by ptuukkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR = srcs

SRC_CHAR = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_tolower.c ft_toupper.c

SRC_LST = ft_lstadd.c ft_lstapp.c ft_lstcapitalize.c ft_lstchr.c \
			ft_lstdel.c ft_lstdelone.c ft_lstfold.c ft_lstfree.c \
			ft_lstiter.c ft_lstjoin.c ft_lstmap.c ft_lstnew.c \
			ft_lstpop.c ft_lstprint.c ft_lstsize.c ft_lsttolower.c \
			ft_lsttouper.c

SRC_MEM = ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memdel.c ft_memdup.c ft_memmove.c ft_memset.c

SRC_MISC = ft_exiterror.c get_next_line.c

SRC_NUM = ft_abs.c ft_atoi.c ft_atoul.c ft_ceil.c ft_ctoi.c ft_dbllen.c \
			ft_dtoa_hex_round.c ft_dtoa_hex.c ft_dtoa_round.c ft_dtoa.c \
			ft_hexincr.c ft_itoa.c ft_ldtoa_hex_round.c ft_ldtoa_hex.c \
			ft_ldtoa.c ft_ltoa.c ft_max.c ft_min.c ft_nbrlen.c ft_pow.c \
			ft_ultoa_base.c parse_double.c vlq_divide_2.c vlq_multiply_2.c \
			vlq_sum.c

SRC_PRINTF = adjust_flags.c adjust_flags2.c convert_a.c convert_b.c \
				convert_c.c convert_d.c convert_double.c convert_e.c \
				convert_e2.c convert_f.c convert_g.c convert_g2.c convert_o.c \
				convert_perc.c convert_px.c convert_s.c convert_u.c \
				ft_printf.c getters.c helper_functions.c read_format.c \
				round_eg.c

SRC_PUT = ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
			ft_putnbr_fd.c ft_putnbr.c ft_putnchar.c ft_putstr_fd.c \
			ft_putstr.c

SRC_STR = ft_strarrdel.c ft_strcapitalize.c ft_strcat.c ft_strchr.c \
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
			ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnstr.c \
			ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c \
			ft_strtolower.c ft_strtoupper.c ft_strtrim.c ft_strtrimchr.c \

OBJDIR = objects

OBJS = $(SRC_CHAR:%.c=$(OBJDIR)/%.o)
OBJS += $(SRC_LST:%.c=$(OBJDIR)/%.o)
OBJS += $(SRC_MEM:%.c=$(OBJDIR)/%.o)
OBJS += $(SRC_MISC:%.c=$(OBJDIR)/%.o)
OBJS += $(SRC_NUM:%.c=$(OBJDIR)/%.o)
OBJS += $(SRC_PRINTF:%.c=$(OBJDIR)/%.o)
OBJS += $(SRC_PUT:%.c=$(OBJDIR)/%.o)
OBJS += $(SRC_STR:%.c=$(OBJDIR)/%.o)

INC = includes/

GCC = gcc -Werror -Wextra -Wall -O3

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)/libft.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

clean:
		/bin/rm -f $(OBJS)
		/bin/rm -rf $(OBJDIR)

fclean : clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
