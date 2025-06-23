# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 23:22:18 by sergio-jime       #+#    #+#              #
#    Updated: 2025/06/24 00:04:31 by sergio-jime      ###   ########.fr        #
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

NAME		:= fdf

# Directories ================================================================ #

SRC_DIR		:= src
INC_DIR		:= include
OBJ_DIR		:= build
LIBFT_DIR	:= libft
LIBFT_A		:= $(LIBFT_DIR)/libft.a
MLX_DIR		:= minilibx-linux

# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS		:= -lm
MLXFLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11

# Files ====================================================================== #

SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)

# Objects ===================================================================== #

OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Rules ====================================================================== #

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "$(BGREEN)Compiling libft$(NC)\n"

$(NAME): $(OBJ_FILES)
	@$(MAKE) -C $(MLX_DIR)
	@printf "$(BGREEN)Compiling minilibx$(NC)\n"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME) $(MLXFLAGS) $(LDFLAGS)
	@printf "$(BGREEN)Built!$(NC)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fdf.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(BLUE)Compiling$(NC)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(RED)Clean objects$(NC)\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(RED)Clean all$(NC)\n"

re: fclean all
	@printf "$(YELLOW)Rebuild completed$(NC)\n"

.PHONY: all clean fclean re