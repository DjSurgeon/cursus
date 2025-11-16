# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 17:05:37 by sergio-jime       #+#    #+#              #
#    Updated: 2025/11/16 20:25:41 by sergio-jime      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##
# @file Makefile
# @brief Build system for the Philosophers project
# This Makefile handles compilation, linking, and cleanup of the philosophers
# simulation program. It supports incremental builds, colored output, and
# progress tracking.
##

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
CFLAGS		:=	-Wall -Wextra -Werror -I$(INC_DIR)

# **************************************************************************** #
# Files ====================================================================== #

SRC_FILES	:=	$(SRC_DIR)/main.c\
				$(SRC_DIR)/clean_utils.c\
				$(SRC_DIR)/create_struct.c\
				$(SRC_DIR)/dinner.c\
				$(SRC_DIR)/fill_struct.c\
				$(SRC_DIR)/monitor_routine.c\
				$(SRC_DIR)/parser.c\
				$(SRC_DIR)/philo_routine.c\
				$(SRC_DIR)/philo_routine2.c\
				$(SRC_DIR)/philo_utils.c\
				$(SRC_DIR)/philo_utils2.c\
				$(SRC_DIR)/routine_utils.c\
				$(SRC_DIR)/routines.c\
				$(SRC_DIR)/time_utils.c

# **************************************************************************** #
# Objects ==================================================================== #

OBJ_FILES	:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# **************************************************************************** #
# Rules ====================================================================== #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/philo.h
	@mkdir -p $(OBJ_DIR)
	@printf "$(BLUE)Compiling $<...$(RESET)\n"
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