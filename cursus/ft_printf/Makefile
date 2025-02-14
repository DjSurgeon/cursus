# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio-jimenez <sergio-jimenez@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 22:16:42 by sergio-jime       #+#    #+#              #
#    Updated: 2025/02/14 00:41:30 by sergio-jime      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE =	ft_printf.c\
			ft_printf_utils.c

OBJ = $(SOURCE:%.c=%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ar rcs $(NAME) $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 