# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/19 16:50:27 by sergio-jime       #+#    #+#              #
#    Updated: 2025/04/22 12:21:15 by sergio-jime      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes ================================================================= #
RED			:= \e[0;31m
GREEN		:= \e[0;32m
BGREEN		:= \e[1;32m
YELLOW		:= \e[0;33m
BLUE		:= \e[0;34m
NC			:= \e[0m

# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -I include

# Directories ================================================================ #

SRC_DIR		:= src/
LIB_DIR		:= lib/
INC_DIR		:= include/
OBJ_DIR		:= build/

# Programs =================================================================== #

CLIENT		:= client
SERVER		:= server

# Files ====================================================================== #

SRC_LIB		:= $(wildcard $(LIB_DIR)/*.c)
SRC_CLIENT	:= $(SRC_DIR)client.c
SRC_SERVER	:= $(SRC_DIR)server.c

# Objects ===================================================================== #

OBJ_LIB		:= $(patsubst $(LIB_DIR)%.c,$(OBJ_DIR)lib/%.o,$(SRC_LIB))
OBJ_CLIENT	:= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)src/%.o,$(SRC_CLIENT))
OBJ_SERVER	:= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)src/%.o,$(SRC_SERVER))

ALL_OBJS	:= $(OBJ_LIB) $(OBJ_CLIENT) $(OBJ_SERVER)

# Rules ====================================================================== #

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)
		@printf "$(BGREEN)Minitalk compilation complete!$(NC)\n"

$(OBJ_DIR)lib/%.o: $(LIB_DIR)%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)Compiling $< $(NC)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)src/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)Compiling $< $(NC)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(OBJ_LIB) $(OBJ_SERVER)
	@printf "$(YELLOW)Linking $@...$(NC)\n"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "$(GREEN)$@ built successfully!$(NC)\n"

$(CLIENT): $(OBJ_LIB) $(OBJ_CLIENT)
	@printf "$(YELLOW)Linking $@...$(NC)\n"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "$(GREEN)$@ built successfully!$(NC)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)Objects cleaned!$(NC)\n"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "$(RED)Executables removed!$(NC)\n"

re: fclean all
	@printf "$(YELLOW)Rebuild complete.$(NC)\n"