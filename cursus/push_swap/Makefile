# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 13:12:04 by sergio-jime       #+#    #+#              #
#    Updated: 2025/05/12 15:42:35 by serjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program ==================================================================== #

NAME := push_swap

# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LIBFT_DIR)

# Directories ================================================================ #

SRC_DIR		:= src
INC_DIR		:= include
OBJ_DIR		:= build
LIBFT_DIR	:= libft
LIBFT_A		:= $(LIBFT_DIR)/libft.a

# Files ====================================================================== #

SRC_LIB		:= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
