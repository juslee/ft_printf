# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 09:55:05 by welee             #+#    #+#              #
#    Updated: 2024/05/20 10:11:18 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
SRCS = $(shell find . -name '*.c')
OBJS = $(SRCS:.c=.o)
EXECS = $(SRCS:.c=)
INCLUDES = -I ../includes

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L../bin -lftprintf
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
# macOS specific settings
	VALGRIND = leaks --atExit --list -- $@
else ifeq ($(UNAME), Linux)
# Linux specific settings
	VALGRIND = valgrind
endif

all: $(EXECS)
%: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LFLAGS)
	$(VALGRIND) $@
	$(RM) $@
clean:
	${RM} $(OBJS) $(EXECS)
fclean: clean
re: fclean all
.PHONY: all clean fclean re
