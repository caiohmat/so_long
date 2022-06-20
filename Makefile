# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 22:30:51 by chideyuk          #+#    #+#              #
#    Updated: 2021/11/25 22:57:41 by chideyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	clean fclean re all

NAME	:= so_long
CFLAGS	:= -Wall -Wextra -Werror -o
XFLAGS	:= -lmlx -lXext -lX11
CC	:= cc
SRCS	:= createtilemap.c \
		end.c \
		error.c \
		img.c \
		key.c \
		main.c \
		mapcheck.c \
		mapread.c \
		move.c \
		start.c \
		update.c \
		utils.c \
		gnlmod/get_next_line_utils.c \
		gnlmod/get_next_linemod.c

all	: $(NAME)

$(NAME)	:
	$(CC) $(CFLAGS) $(NAME) $(SRCS) $(XFLAGS)

clean	:

fclean	: clean
	rm -f $(NAME)

re	: fclean all
