# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 15:14:56 by dicarval          #+#    #+#              #
#    Updated: 2024/08/16 15:41:50 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SRC = fdf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -Lmlibx -lmlx -L/usr/local/lib -Lmlibx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -Imlibx -I/usr/local/include -Lmlibx -lmlx -lXext -lX11 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
