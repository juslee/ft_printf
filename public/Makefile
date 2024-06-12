# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 12:23:55 by welee             #+#    #+#              #
#    Updated: 2024/06/12 09:00:13 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC = srcs/mandatory/ft_printf.c srcs/mandatory/ft_vprintf.c srcs/mandatory/handle_format.c \
	srcs/mandatory/ft_putchar.c srcs/mandatory/ft_putstr.c srcs/mandatory/ft_putnbr.c \
	srcs/mandatory/ft_putunbr.c srcs/mandatory/ft_puthex.c srcs/mandatory/ft_putptr.c
OBJ = $(SRC:srcs/mandatory/%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

objs/%.o: srcs/mandatory/%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
