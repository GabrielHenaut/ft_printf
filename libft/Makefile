# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 14:54:52 by ghenaut-          #+#    #+#              #
#    Updated: 2022/06/23 15:30:24 by ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: .c.o libft.a all clean fclean re bonus

SRCS	= 	ft_memset.c \
			ft_strlen.c \
			ft_substr.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memjoin.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_strtoupper.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_itox.c \
			ft_uitoa.c \
			ft_uitoa.c \
			ft_uitox.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strrchr.c \
			
BONUS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			

OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS:.c=.o)
NAME	= libft.a


.c.o:
	@cc -Wall -Wextra -Werror -c $< -I . -o $(<:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

all: $(NAME)
	

bonus:	$(OBJS) $(BONUS_OBJS)
	@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	@ranlib $(NAME)
	

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
