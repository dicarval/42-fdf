# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 15:14:56 by dicarval          #+#    #+#              #
#    Updated: 2024/09/09 12:19:05 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

CC =		cc
CFLAGS =	-g -Wall -Wextra -Werror

SRC =		check_map.c close_fdf.c draw_map.c main.c\
			map_loading.c map_to_point.c pixel_put.c range_to_screen.c

OBJ =		$(SRC:.c=.o)

MINILIBX =	-Lmlibx -lmlx -lXext -lX11 -lm -lz
LIBFT =		./libft/libft.a
PRINTF =	./ft_printf/libftprintf.a

all:		$(NAME)

$(LIBFT):
			@make -s -C ./libft/
			@echo "FdF - Libft compiled"

$(PRINTF):
			@make -s -C ./ft_printf/
			@echo "FdF - Printf compiled"

$(NAME):	$(OBJ) $(LIBFT) $(PRINTF)
			@echo "FdF - Objects files created"
			@make -s -C ./mlibx/
			@echo "FdF - MiniLibx compiled"
			@$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME)
			@echo "FdF - FdF executable created"

%.o:		%.c
			@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
			@rm -f $(OBJ)
			@echo "FdF - Objects files deleted"

fclean:		clean
			@rm -f $(NAME)
			@make clean -s -C ./mlibx/
			@make fclean -s -C ./libft/
			@make fclean -s -C ./ft_printf/
			@echo "FdF - Libraries and executables deleted"

re:			fclean all

.PHONY:		all clean fclean re
