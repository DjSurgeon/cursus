# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 13:12:04 by sergio-jime       #+#    #+#              #
#    Updated: 2025/03/22 01:49:04 by sergio-jime      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories

SRCDIR = src
INCDIR = include
OBJDIR = obj
# LIBFTDIR = libft

# SOURCE files
SOURCE = $(wildcar *.c)

# Compiler flags

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCDIR) -I$(LIBFTDIR)

OBJ = $(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re