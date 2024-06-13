# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:19:51 by welee             #+#    #+#              #
#    Updated: 2024/06/13 10:02:06 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bin/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

MANDATORY_SRC = srcs/mandatory/ft_printf.c srcs/mandatory/ft_vprintf.c srcs/mandatory/handle_format.c \
	srcs/mandatory/ft_putchar.c srcs/mandatory/ft_putstr.c srcs/mandatory/ft_putnbr.c \
	srcs/mandatory/ft_putunbr.c srcs/mandatory/ft_puthex.c srcs/mandatory/ft_putptr.c
MANDATORY_OBJ = $(MANDATORY_SRC:srcs/mandatory/%.c=objs/mandatory/%.o)

BONUS_SRC = srcs/bonus/handle_format.c \
	srcs/bonus/ft_hexlen.c srcs/bonus/ft_nbrlen.c srcs/bonus/ft_strlen.c srcs/bonus/ft_unbrlen.c \
	srcs/bonus/handle_char.c srcs/bonus/handle_hex.c srcs/bonus/handle_nbr.c srcs/bonus/handle_ptr.c \
	srcs/bonus/handle_str.c srcs/bonus/handle_unbr.c srcs/bonus/init_format.c srcs/bonus/parse_flags.c \
	srcs/bonus/parse_precision.c srcs/bonus/parse_width.c
BONUS_OBJ = $(BONUS_SRC:srcs/bonus/%.c=objs/bonus/%.o)
BONUS_ALL_OBJ = $(filter-out objs/mandatory/handle_format.o, $(MANDATORY_OBJ)) $(BONUS_OBJ)

all: $(NAME)

bonus: $(NAME)_bonus

$(NAME)_bonus: $(BONUS_OBJ) $(MANDATORY_OBJ)
	mkdir -p bin
	rm -f $(NAME)
	ar rcs $(NAME) $(BONUS_ALL_OBJ)

$(NAME): $(MANDATORY_OBJ)
	mkdir -p bin
	rm -f $(NAME)
	ar rcs $@ $^

objs/mandatory/%.o: srcs/mandatory/%.c
	mkdir -p objs/mandatory
	$(CC) $(CFLAGS) -c $< -o $@

objs/bonus/%.o: srcs/bonus/%.c
	mkdir -p objs/bonus
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)
	$(MAKE) -C tests clean

fclean: clean
	rm -f $(NAME) tests/test_ft_printf tests/test_ft_printf_bonus

re: fclean all

tests: $(NAME)
	$(MAKE) -C tests

bonus_tests: bonus
	$(MAKE) -C tests bonus_tests

norm:
	norminette includes/*.h srcs/mandatory/*.c srcs/bonus/*.c

dist:
	rm -rf dist
	mkdir -p dist/includes dist/srcs/mandatory dist/srcs/bonus
	cp -r includes/*.h dist/includes/
	cp -r srcs/mandatory/*.c dist/srcs/mandatory/
	cp -r srcs/bonus/*.c dist/srcs/bonus/
	cp public/Makefile dist/

.PHONY: all bonus clean fclean re tests bonus_tests norm dist
