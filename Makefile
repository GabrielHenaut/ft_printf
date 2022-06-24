# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 19:39:47 by ghenaut-          #+#    #+#              #
#    Updated: 2022/06/24 23:27:46 by Ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME =libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS =	./sources/mandatory/append_to_str.c \
		./sources/mandatory/ft_print_nbr.c	\
		./sources/mandatory/ft_printf.c \
		./sources/mandatory/ft_putaddr.c \
		./sources/mandatory/ft_putnbr_base.c \
		./sources/mandatory/ft_vprintf.c \
		./sources/mandatory/parse_arg.c \
		./sources/mandatory/generate_rtn_str.c

BONUS = ./sources/bonus/ft_printf_bonus.c \
		./sources/bonus/add_char_bonus.c \
		./sources/bonus/add_str_bonus.c \
		./sources/bonus/ft_vprintf_bonus.c \
		./sources/bonus/generate_rtn_str_bonus.c \
		./sources/bonus/handle_conversions_bonus.c \
		./sources/bonus/parse_arg_bonus.c \
		./sources/bonus/utils_bonus.c \
		./sources/bonus/add_int_bonus.c \
		./sources/bonus/add_uint_bonus.c \
		./sources/bonus/add_hex_bonus.c \
		./sources/bonus/add_pointer_bonus.c \
		./sources/bonus/add_percent_bonus.c \
		./sources/bonus/handle_precision_bonus.c \


BONUS_OBJS = $(BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@mv ./libft/libft.a ./$(NAME)
	@ar -rcs $(NAME) $(OBJS) 

bonus: $(BONUS_OBJS)
	@make -C ./libft
	@mv ./libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(BONUS_OBJS)

%.o : %.c ./includes/ft_printf.h
	@$(CC) $(FLAGS) -c $< -o $@ -I ./includes

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf ./libft/*.o

fclean: clean
	@rm -rf *.a

re: fclean all 

.PHONY: all fclean clean re bonus