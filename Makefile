# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 15:14:56 by dicarval          #+#    #+#              #
#    Updated: 2024/08/28 16:37:28 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

CC =		cc
CFLAGS =	-Wall -Wextra -Werror -g

SRC =		bresnham.c check_map.c close_fdf.c draw_map.c \
			main.c map_creation.c read_map.c

OBJ =		$(SRC:.c=.o)

MINILIBX =	-Lmlibx -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz
LIBFT =		./libft/libft.a
PRINTF =	./ft_printf/libftprintf.a

all:		$(NAME)

$(LIBFT):
			make -C ./libft/

$(PRINTF):
			make -C ./ft_printf/


$(NAME):	$(OBJ) $(LIBFT) $(PRINTF)
			$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME)

%.o:		%.c
#make -C ./mlibx/
			$(CC) $(CC_FLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
#make clean -C ./mlibx/
			make fclean -C ./libft/
			make fclean -C ./ft_printf/
re:			fclean all

.PHONY:		all clean fclean re

map:
		@make
		./fdf ./Maps/42.fdf
