# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 23:41:16 by serjimen          #+#    #+#              #
#    Updated: 2025/06/02 12:08:23 by serjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes ================================================================= #
RED			:= \e[0;31m
GREEN		:= \e[0;32m
BGREEN		:= \e[1;32m
YELLOW		:= \e[0;33m
BLUE		:= \e[0;34m
NC			:= \e[0m

# Program ==================================================================== #

NAME		:= libft.a

# Directories ================================================================ #

SRC_DIR		:= src
OBJ_DIR		:= build
INC_DIR		:= include

# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I$(INC_DIR)

# Files ====================================================================== #

SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Rules ====================================================================== #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)
	@printf "$(GREEN)$(NAME) Ready!, compile completed$(NC)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/libft.h
	@mkdir -p $(OBJ_DIR)
	@printf "$(BLUE)Creating objects $< $(NC)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)Clean objects$(NC)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)Clean library$(NC)\n"

re: fclean all
	@printf "$(YELLOW)Rebuild completed$(NC)\n"

.PHONY: all clean fclean re
