# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio <sergio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 23:22:18 by sergio-jime       #+#    #+#              #
#    Updated: 2026/05/20 22:36:20 by sergio           ###   ########.fr        #
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
CFLAGS		:= -Wall -Wextra -Werror -g -std=gnu99 -D BUFFER_SIZE=4096 -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS		:= -lm
MLXFLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11

# Files ====================================================================== #

SRC_FILES	:=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/parser/check_arguments.c \
				$(SRC_DIR)/parser/check_utils.c \
				$(SRC_DIR)/parser/parse_map.c \
				$(SRC_DIR)/graphics/mlx_init.c \
				$(SRC_DIR)/graphics/mlx_draw.c \
				$(SRC_DIR)/graphics/mlx_bresenham.c \
				$(SRC_DIR)/graphics/mlx_hooks.c \
				$(SRC_DIR)/graphics/mlx_utils.c \
				$(SRC_DIR)/memory/free_structs.c \
				$(SRC_DIR)/utils/check_errors.c

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
	@mkdir -p $(dir $@)
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