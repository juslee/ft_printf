# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 09:55:05 by welee             #+#    #+#              #
#    Updated: 2024/06/12 13:48:50 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_ft_printf
BONUS_NAME = test_ft_printf_bonus
LIB = ../bin/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../includes

MANDATORY_SRC = mandatory/test_ft_printf.c
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

BONUS_SRC = bonus/test_ft_printf_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus_tests: $(BONUS_NAME)

$(NAME): $(MANDATORY_OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME): $(BONUS_OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(LIB):
	$(MAKE) -C ..

clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus_tests clean fclean re
