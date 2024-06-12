# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 09:55:05 by welee             #+#    #+#              #
#    Updated: 2024/06/12 11:06:30 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_ft_printf
LIB = ../bin/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../includes

SRC = mandatory/test_ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(LIB):
	$(MAKE) -C ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
