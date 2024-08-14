/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/14 13:50:18 by dicarval         ###   ########.fr       */
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
# include "./mlx_linux/mlx.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 800
# define MLX_ERROR 1

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		map_num;
	int		max_argv;
	char	**map_file;
	int		**map_content;
	t_point	**point_map;
	int		nb_lines;
}	t_data;


#endif
