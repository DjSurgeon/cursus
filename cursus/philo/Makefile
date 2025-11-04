# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: serjimen <serjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 17:05:37 by sergio-jime       #+#    #+#              #
#    Updated: 2025/11/04 14:08:36 by serjimen         ###   ########.fr        #
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

NAME		:= philo

# Directories ================================================================ #

SRC_DIR		:= src
INC_DIR		:= include
OBJ_DIR		:= build

# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3 -I$(INC_DIR)

# Files ====================================================================== #

SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)

# Objects ===================================================================== #

OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Rules ====================================================================== #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@printf "$(BGREEN)Built!$(NC)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/philo.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(BLUE)Compiling$(NC)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)Clean objects$(NC)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)Clean all$(NC)\n"

re: fclean all
	@printf "$(YELLOW)Rebuild completed$(NC)\n"

.PHONY: all clean fclean re