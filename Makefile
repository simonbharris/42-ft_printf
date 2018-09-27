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

# Makefile for
NAME = libftprintf.a

# Directories
SRC_DIR = ./
OBJ_DIR = ./
INC_DIR = ./libft/includes/
LIBFT_DIR = libft

# GNL files
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
			pf_b.c

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
			ft_wstrjoin.c

LIBFT_SRC = $(LIBFT_FILES:%=$(LIBFT_DIR)/src/%)

SRC = $(SRC_FILES:%=$(SRC_DIR)%)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFTOBJ = $(LIBFT_SRC:$(LIBFT_DIR)/src/%.c=$(LIBFT_DIR)/obj/%.o)
# Libft files
LIBFT = $(LIBFT_DIR)/libft.a

# Compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = -I $(LIBFT_DIR)/includes
LIB = -L$(LIBFT_DIR) -lft

AR = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): libft $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(LIBFTOBJ)

libft: $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ): %.o : %.c
	$(CC) $(FLAGS) -c $(INC) -o $@ $<

$(LIBFTOBJ) : libft/obj/%.o : libft/src/%.c : libft
	$(CC) $(FLAGS) -c $(INC) -o $@ $<

# debug: $(LIBFT)
# 	$(CC) -g $(INC) $(LIB) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY : all, re, clean, fclean, libft