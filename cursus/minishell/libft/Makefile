# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 12:24:16 by vjan-nie          #+#    #+#              #
#    Updated: 2025/05/22 13:49:14 by vjan-nie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libft.a

SRC			=	ft_atoi.c\
				ft_split.c\
				ft_bzero.c\
				ft_strchr.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_strjoin.c\
				ft_isascii.c\
				ft_strlcat.c\
				ft_isdigit.c\
				ft_strlcpy.c\
				ft_isprint.c\
				ft_strlen.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_memchr.c\
				ft_strncmp.c\
				ft_memcmp.c\
				ft_strnstr.c\
				ft_memcpy.c\
				ft_strrchr.c\
				ft_memmove.c\
				ft_strtrim.c\
				ft_memset.c\
				ft_substr.c\
				ft_putchar_fd.c\
				ft_tolower.c\
				ft_putendl_fd.c\
				ft_toupper.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_striteri.c\
				ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c

FT_PRINTF	=	ft_printf/ft_printf.c\
				ft_printf/len_int_nbr.c\
				ft_printf/write_char.c\
				ft_printf/write_hex.c\
				ft_printf/write_int_nbr.c\
				ft_printf/write_ptr.c\
				ft_printf/write_str.c\
				ft_printf/write_uns_int_nbr.c

GNL			=	get_next_line/get_next_line_bonus.c

CC			= 	cc
CFLAGS		= 	-Wall -Wextra -Werror
INCLUDE_DIR = 	include
OBJ			= 	$(SRC:.c=.o) $(FT_PRINTF:.c=.o) $(GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
