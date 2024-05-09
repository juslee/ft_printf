# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:19:51 by welee             #+#    #+#              #
#    Updated: 2024/05/09 20:40:52 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_DIR = libft
SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes
TEST_DIR = tests
DIST_DIR = dist
BIN_DIR = bin
DOCS_DIR = docs

INCLUDES = -I ${INCLUDES_DIR} -I ${LIBFT_DIR}/bin
CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -Llibft/bin -lft
LIBC = ar rcs
RM = rm -f
MAKE = make -C
MKDIR = mkdir -p

SRCS = $(shell find $(SRCS_DIR) -name '*.c')
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
HEADERS = $(wildcard $(INCLUDES_DIR)/ft_*.h)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

DOXYGEN = doxygen
DOXYGEN_CONFIG = Doxyfile

all: $(LIBFT_DIR) ${NAME}

$(NAME): $(OBJS)
	$(MKDIR) $(BIN_DIR)
	$(LIBC) $(BIN_DIR)/$(NAME) $(LIBFT_DIR)/bin/libft.a $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR):
	$(MAKE) $(DIST_DIR) all

clean:
	$(RM) $(OBJS)
	$(RM) -r $(DIST_DIR)
	$(MAKE) $(TEST_DIR) clean

fclean: clean
	$(RM) $(BIN_DIR)/$(NAME)

re: fclean all dist

bonus: all

norm:
	$(NORM) $(NORM_FLAGS) $(SRCS_DIR) $(INCLUDES_DIR)

tests: all
	$(MAKE) $(TEST_DIR) all

docs:
	${DOXYGEN} ${DOXYGEN_CONFIG}

.PHONY: all clean fclean re bonus norm tests docs
