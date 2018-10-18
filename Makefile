# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/19 15:50:45 by sharris           #+#    #+#              #
#    Updated: 2018/08/19 16:41:27 by sharris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILES = ft_printf.c \
			get_drcv.c \
			drcv_util.c \
			put_drcv.c \
			pf_di.c \
			pf_o.c \
			pf_u.c \
			pf_x.c \
			pf_s.c \
			pf_c.c \
			pf_p.c \
			pf_prec.c \
			pf_zero.c \
			pf_pad.c \
			pf_space.c \
			pf_sign.c \
			pf_b.c \
			flag_util.c

LIBFT_FILES = \
			ft_itoabase.c \
			ft_strnew.c \
			ft_wstrdup.c \
			ft_wstrnew.c \
			ft_lltoa.c \
			ft_strffjoin.c \
			ft_strlen.c \
			ft_wstrffjoin.c \
			ft_wstrlen.c \
			ft_memdel.c \
			ft_strcfjoin.c \
			ft_strsub.c \
			ft_strdup.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_strchr.c \
			ft_strnequ.c \
			ft_tolower.c \
			ft_putstr.c \
			ft_putwstr.c \
			ft_putchar.c \
			ft_wstrsub.c \
			ft_memset.c \
			ft_memalloc.c \
			ft_strcpy.c \
			ft_strjoin.c \
			ft_wstrjoin.c \
			ft_wstrcpy.c \
			ft_memcpy.c

LIBFT_DIR = libft/
LIBFT_NAME = $(LIBFT_DIR)libft.a
LIBFT = -L $(LIBFT_DIR) -l ft

OBJ = $(SRC_FILES:%.c=%.o)
LIBFT_OBJ = $(LIBFT_FILES:%.c=$(LIBFT_DIR)obj/%.o)
INC = -I libft/includes

CC = gcc
WFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

all: $(NAME)

$(OBJ): %.o : %.c
	$(CC) -c $(INC) $< -o $@

$(NAME): $(OBJ) $(LIBFT_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(LIBFT_OBJ) $(OBJ) 

$(LIBFT_OBJ):
	make re -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all, clean, fclean, re