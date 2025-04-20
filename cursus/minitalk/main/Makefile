# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/19 16:50:27 by sergio-jime       #+#    #+#              #
#    Updated: 2025/04/19 17:30:12 by sergio-jime      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -I include

# Directories ================================================================ #

SRC_DIR		:= src/
LIB_DIR		:= lib/
INC_DIR		:= include/

# Programs =================================================================== #

CLIENT		:= client
SERVER		:= server

# Files ====================================================================== #

SRC_LIB		:= $(wildcard $(LIB_DIR)*.c)
SRC_CLIENT	:= $(SRC_DIR)client.c
SRC_SERVER	:= $(SRC_DIR)server.c

OBJ_LIB		:= $(SRC_LIB:.c=.o)
OBJ_CLIENT	:= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	:= $(SRC_SERVER:.c=.o)

# Rules ====================================================================== #

all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(OBJ_LIB) $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT): $(OBJ_LIB) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ_LIB) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re