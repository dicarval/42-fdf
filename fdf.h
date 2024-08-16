/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/16 15:45:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysym.h>
//# include <mlx.h>
# include "./libft/libft.h"
# include "./libft/libft.h"
# include "./mlibx/mlx.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 800
# define MLX_ERROR 1

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}	t_point;

typedef struct s_screen
{
	int			min_x;
	int			min_y;
	int			max_y;
	int			max_x;
}	t_screen;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			map_num;
	int			max_argv;
	char		**map_file;
	int			**map_content;
	t_point		**point_map;
	int			nb_lines;
	int			nb_colls;
	int			max_z;
	int			min_z;
	int			new_max_z;
	float		z_modify;
//	int			nb_view;
	float		angle_z;
	float		angle_x;
	float		angle_y;
	float		size_grid;
	t_screen	screen;
}	t_data;

#endif
