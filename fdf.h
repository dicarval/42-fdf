/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/19 14:29:47 by dicarval         ###   ########.fr       */
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

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1200
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
	int		x;
	int		y;
	int		z;
}	t_point;

typedef struct s_param
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_param;

typedef struct s_screen
{
	float			min_x;
	float			min_y;
	float			max_y;
	float			max_x;
}	t_screen;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_point		**point_map;
	t_screen	screen;
	int			map_num;
	int			max_argv;
	char		**map_file;
	int			**map_content;
	int			height;
	int			width;
	int			max_z;
	int			min_z;
	int			new_max_z;
	float		z_modify;
	float		angle_z;
	float		angle_x;
	float		angle_y;
	float		size_grid;
}	t_data;

#endif
