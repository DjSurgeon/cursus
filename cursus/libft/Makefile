# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio <sergio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 23:41:16 by serjimen          #+#    #+#              #
#    Updated: 2026/04/04 11:38:50 by sergio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors ===================================================================== #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Library ==================================================================== #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj

SOURCE = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_countchar.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
			ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SOURCE:%.c=%.o))

# Progress calculations
TOTAL_FILES = $(words $(SOURCE))
CURRENT_FILE = 0

# Rules ====================================================================== #

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "\n$(GREEN)✨ $(NAME) created successfully! ✨$(DEF_COLOR)\n"

$(OBJ_DIR)/%.o: %.c libft.h
	@mkdir -p $(OBJ_DIR)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "$(BLUE)🔨 Compiling [$(CURRENT_FILE)/$(TOTAL_FILES)]: $(CYAN)%-20s$(DEF_COLOR)\r" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)🧹 Object files removed.$(DEF_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)🗑️  $(NAME) removed.$(DEF_COLOR)\n"

re: fclean
	@$(MAKE) all

# Deep Static Analysis with a "AI-like" Spinner
analyze:
	@printf "$(MAGENTA)🧠 analyzing your code... $(DEF_COLOR)"
	@# Small script to simulate a spinner while cc runs
	@($(CC) $(CFLAGS) -fanalyzer -c $(SOURCE) > /dev/null 2>&1 && printf "$(GREEN)DONE! ✅\n$(DEF_COLOR)" || printf "$(RED)FAILED! ❌\n$(DEF_COLOR)") & \
	PID=$$!; \
	sp='/-\|'; \
	while kill -0 $$PID 2>/dev/null; do \
		printf "\b$${sp:i++%4:1}"; \
		sleep 0.1; \
	done
	@rm -f *.o

test: all
	@chmod +x test/scripts/test_libft.sh
	@cd test/scripts && ./test_libft.sh

help:
	@printf "$(WHITE)Libft Makefile Help:$(DEF_COLOR)\n"
	@printf "  $(CYAN)all     $(DEF_COLOR): Compiles the library (libft.a)\n"
	@printf "  $(CYAN)clean   $(DEF_COLOR): Removes the object directory (obj/)\n"
	@printf "  $(CYAN)fclean  $(DEF_COLOR): Removes object directory and the library\n"
	@printf "  $(CYAN)re      $(DEF_COLOR): Performs a full re-compilation\n"
	@printf "  $(CYAN)test    $(DEF_COLOR): Compiles and runs the test suite\n"
	@printf "  $(CYAN)analyze $(DEF_COLOR): Performs a deep static analysis\n"
	@printf "\n"
	@printf "$(GRAY)Tip: Use 'make -j\$$(nproc)' for fast parallel compilation.$(DEF_COLOR)\n"

.PHONY: all clean fclean re bonus test analyze help
