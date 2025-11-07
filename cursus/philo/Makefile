# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 17:05:37 by sergio-jime       #+#    #+#              #
#    Updated: 2025/11/07 13:26:52 by sergio-jime      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##
# @file Makefile
# @brief Build system for the Philosophers project
# This Makefile handles compilation, linking, and cleanup of the philosophers
# simulation program. It supports incremental builds, colored output, and
# progress tracking.
# @note Follows 42 School norms with strict compiler flags
# @note Creates build directory structure automatically
# @warning Requires GCC or compatible compiler
# @warning Object files are stored in separate build/ directory
#

# **************************************************************************** #
# Color codes ================================================================ #
RED			:=	\e[0;31m
GREEN		:=	\e[0;32m
BGREEN		:=	\e[1;32m
YELLOW		:=	\e[0;33m
BLUE		:=	\e[0;34m
RESET		:=	\e[0m

# **************************************************************************** #
# Program ==================================================================== #

NAME		:=	philo

# **************************************************************************** #
# Directories ================================================================ #

SRC_DIR		:=	src
INC_DIR		:=	include
OBJ_DIR		:=	build

# **************************************************************************** #
# Compiler =================================================================== #

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g3 -I$(INC_DIR)

# **************************************************************************** #
# Files ====================================================================== #

SRC_FILES	:=	$(SRC_DIR)/main.c\
				$(SRC_DIR)/parser.c\
				$(SRC_DIR)/create_struct.c\
				$(SRC_DIR)/fill_struct.c\
				$(SRC_DIR)/philo_utils.c\
				$(SRC_DIR)/tester.c

# **************************************************************************** #
# Objects ==================================================================== #

OBJ_FILES	:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# **************************************************************************** #
# Progress variables ========================================================= #
TOTAL_FILES := $(words $(SRC))
COMPILED_FILES = 0

# **************************************************************************** #
# Rules ====================================================================== #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/philo.h
	@mkdir -p $(OBJ_DIR)
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
	@printf "$(BLUE)[%2d/%2d]$(RESET) Compiling $<...\r" $(COMPILED_FILES) $(TOTAL_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✓ Clean complete!$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Full clean complete!$(RESET)"

re: fclean all
	@printf "$(YELLOW)Rebuild completed$(RESET)\n"

.PHONY: all clean fclean re