# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 16:03:21 by serjimen          #+#    #+#              #
#    Updated: 2025/05/07 14:13:48 by serjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = exercises.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRCS    =	ex01.c \
			ex02.c \
			ex03.c \
			ex04.c

OBJS    = $(SRCS:.c=.o)

HEADER  = exercises.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
