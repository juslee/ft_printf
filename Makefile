# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:19:51 by welee             #+#    #+#              #
#    Updated: 2024/05/26 09:17:26 by welee            ###   ########.fr        #
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
PUBLIC_DIR = public

INCLUDES = -I ${INCLUDES_DIR} -I ${LIBFT_DIR}/bin
CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -Llibft/bin -lft
LIBC = ar rcs
RM = rm -f
MAKE = make -C
MKDIR = mkdir -p
CP = cp -f
FRANCINETTE = francinette
FRANCINETTE_FLAGS = -s
WHOAMI = whoami

SRCS = $(shell find $(SRCS_DIR) -name '*.c' ! -name '*_bonus.c')
BSRCS = $(shell find $(SRCS_DIR) -name '*.c' ! -name 'ft_handle_format.c')
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BOBJS = $(BSRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
HEADERS = $(wildcard $(INCLUDES_DIR)/ft_*.h)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

DOXYGEN = doxygen
DOXYGEN_CONFIG = Doxyfile

all: $(NAME)

$(NAME): $(OBJS)
	$(MKDIR) $(BIN_DIR)
	$(LIBC) $(BIN_DIR)/$(NAME) $(OBJS)

bonus: $(BOBJS)
	$(MKDIR) $(BIN_DIR)
	$(LIBC) $(BIN_DIR)/$(NAME) $(BOBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(BIN_DIR)/$(NAME)

re: fclean all dist

dist:
	@$(MKDIR) $(DIST_DIR)
	@$(foreach src,$(SRCS),cp $(src) $(DIST_DIR);)
	@find $(INCLUDES_DIR) -type f -exec cp {} $(DIST_DIR) \;
	@$(CP) $(PUBLIC_DIR)/Makefile $(DIST_DIR)
	@echo $(shell $(WHOAMI)) > $(DIST_DIR)/author

norm:
	$(NORM) $(NORM_FLAGS) $(SRCS_DIR) $(INCLUDES_DIR)

tests: all
	$(MAKE) $(TEST_DIR) all

tests_bonus: bonus
	$(MAKE) $(TEST_DIR) all

docs:
	${DOXYGEN} ${DOXYGEN_CONFIG}

.PHONY: all clean fclean re dist norm tests docs
