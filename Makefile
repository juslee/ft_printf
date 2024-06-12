# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:19:51 by welee             #+#    #+#              #
#    Updated: 2024/06/12 11:05:42 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NNAME = bin/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC = srcs/mandatory/ft_printf.c srcs/mandatory/ft_vprintf.c srcs/mandatory/handle_format.c \
\tsrcs/mandatory/ft_putchar.c srcs/mandatory/ft_putstr.c srcs/mandatory/ft_putnbr.c \
\tsrcs/mandatory/ft_putunbr.c srcs/mandatory/ft_puthex.c srcs/mandatory/ft_putptr.c
OBJ = $(SRC:srcs/mandatory/%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p bin
	ar rcs $@ $^

objs/%.o: srcs/mandatory/%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C tests clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C tests fclean

re: fclean all

tests: $(NAME)
	$(MAKE) -C tests

norm:
	norminette includes/*.h srcs/mandatory/*.c

dist:
	rm -rf dist
	mkdir -p dist/includes dist/srcs/mandatory
	cp -r includes/*.h dist/includes/
	cp -r srcs/mandatory/*.c dist/srcs/mandatory/
	cp public/Makefile dist/

.PHONY: all clean fclean re tests norm dist
