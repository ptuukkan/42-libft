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

SD_BST = srcs/ft_bst
SD_CHAR = srcs/ft_char
SD_LST = srcs/ft_lst
SD_MEM = srcs/ft_mem
SD_MISC = srcs/ft_misc
SD_NUM = srcs/ft_num
SD_PRINTF = srcs/ft_printf
SD_PUT = srcs/ft_put
SD_STR = srcs/ft_str

SRC_BST = ft_avltapply_level.c ft_avltbalance.c ft_avltcount.c \
			ft_avltheight.c ft_avltinsert.c ft_avltnew.c ft_avltprint.c \
			ft_avltrotate_left.c ft_avltrotate_right.c ft_btreenew.c \
			ft_btreeprefix.c ft_btreedel.c ft_btreefree.c

SRC_CHAR = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_tolower.c ft_toupper.c

SRC_LST = ft_lstadd.c ft_lstapp.c ft_lstcapitalize.c ft_lstchr.c \
			ft_lstcount.c ft_lstdel.c ft_lstdelone.c ft_lstfold.c \
			ft_lstfree.c ft_lstiter.c ft_lstjoin.c ft_lstmap.c ft_lstnew.c \
			ft_lstpop.c ft_lstprint.c ft_lstsize.c ft_lsttolower.c \
			ft_lsttoupper.c ft_twlstadd.c ft_twlstapp.c \
			ft_twlstcount.c ft_twlstdelone.c ft_twlstdetach.c ft_twlstnew.c \
			ft_twlstdel.c

SRC_MEM = ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memdel.c ft_memdup.c ft_memmove.c ft_memset.c

SRC_MISC = ft_exiterror.c get_next_line.c

SRC_NUM = ft_abs.c ft_atoi.c ft_atoll.c ft_atoul.c ft_ceil.c ft_ctoi.c \
			ft_dbllen.c ft_dtoa_hex_round.c ft_dtoa_hex.c ft_dtoa_round.c \
			ft_dtoa.c ft_hexincr.c ft_itoa.c ft_ldtoa_hex_round.c \
			ft_ldtoa_hex.c ft_ldtoa.c ft_ltoa.c ft_max.c ft_min.c ft_nbrlen.c \
			ft_numcmp.c ft_pow.c ft_ultoa_base.c parse_double.c \
			vlq_divide_2.c vlq_multiply_2.c vlq_sum.c

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
			ft_strrchr.c ft_strreplace.c ft_strrev.c ft_strsplit.c \
			ft_strstr.c ft_strsub.c ft_strtolower.c ft_strtoupper.c \
			ft_strtrim.c ft_strtrimchr.c

OBJDIR = objects

OBJ_BST = $(SRC_BST:%.c=$(OBJDIR)/%.o)
OBJ_CHAR = $(SRC_CHAR:%.c=$(OBJDIR)/%.o)
OBJ_LST = $(SRC_LST:%.c=$(OBJDIR)/%.o)
OBJ_MEM = $(SRC_MEM:%.c=$(OBJDIR)/%.o)
OBJ_MISC = $(SRC_MISC:%.c=$(OBJDIR)/%.o)
OBJ_NUM = $(SRC_NUM:%.c=$(OBJDIR)/%.o)
OBJ_PRINTF = $(SRC_PRINTF:%.c=$(OBJDIR)/%.o)
OBJ_PUT = $(SRC_PUT:%.c=$(OBJDIR)/%.o)
OBJ_STR = $(SRC_STR:%.c=$(OBJDIR)/%.o)

OBJS = $(OBJ_BST) $(OBJ_CHAR) $(OBJ_LST) $(OBJ_MEM) $(OBJ_MISC) $(OBJ_NUM) \
			 $(OBJ_PRINTF) $(OBJ_PUT) $(OBJ_STR)

INC = includes/

GCC = gcc -Werror -Wextra -Wall -O3

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_BST): $(OBJDIR)/%.o: $(SD_BST)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

$(OBJ_CHAR): $(OBJDIR)/%.o: $(SD_CHAR)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

$(OBJ_LST): $(OBJDIR)/%.o: $(SD_LST)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

$(OBJ_MEM): $(OBJDIR)/%.o: $(SD_MEM)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

$(OBJ_MISC): $(OBJDIR)/%.o: $(SD_MISC)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

$(OBJ_NUM): $(OBJDIR)/%.o: $(SD_NUM)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

$(OBJ_PRINTF): $(OBJDIR)/%.o: $(SD_PRINTF)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

$(OBJ_PUT): $(OBJDIR)/%.o: $(SD_PUT)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

$(OBJ_STR): $(OBJDIR)/%.o: $(SD_STR)/%.c $(INC)/libft.h $(INC)/ft_printf.h
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(GCC) -c $< -o $@ -I $(INC)

clean:
		/bin/rm -f $(OBJS)
		/bin/rm -rf $(OBJDIR)

fclean : clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all


