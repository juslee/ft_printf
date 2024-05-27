# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 09:55:05 by welee             #+#    #+#              #
#    Updated: 2024/05/27 10:38:42 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
SRCS = $(shell find . -name '*.c' ! -name '*_bonus.c')
BSRCS = $(shell find . -name '*.c' ! -name 'ft_handle_format.c')
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
EXECS = $(SRCS:.c=)
BEXECS = $(BSRCS:.c=)
INCLUDES = -I ../includes

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L../bin -lftprintf
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
# macOS specific settings
	VALGRIND = leaks --atExit --list --
else ifeq ($(UNAME), Linux)
# Linux specific settings
	VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
endif

all: $(EXECS)
%: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LDFLAGS)
	$@
	$(VALGRIND) $@
	$(RM) $@
bonus: $(BEXECS)
clean:
	${RM} $(OBJS) $(EXECS) $(BOBJS) $(BEXECS)
fclean: clean
re: fclean all
.PHONY: all clean fclean re
