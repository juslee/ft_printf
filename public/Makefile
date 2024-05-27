# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 12:23:55 by welee             #+#    #+#              #
#    Updated: 2024/05/27 10:40:27 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
MKDIR = mkdir -p

SRCS = $(shell find . -name '*.c' ! -name '*_bonus.c')
BSRCS = $(shell find . -name '*.c' ! -name 'ft_handle_format.c')
OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BSRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(RM) $(NAME)
	${LIBC} ${NAME} ${OBJS}

bonus: $(BOBJS)
	$(RM) $(NAME)
	${LIBC} ${NAME} ${BOBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
