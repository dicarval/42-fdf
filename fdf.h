/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/26 18:37:35 by dicarval         ###   ########.fr       */
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
# include "./libft/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./mlibx/mlx.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1200
# define MLX_ERROR 1
# define DEFAULT_ANG 0.523599

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
	int			z_adapted;
	int			x_pos;
	int			y_pos;
	double		angle_x;
	double		angle_y;
	double		def_angle;
	float		size_grid;
}	t_data;

//Map checking
int		check_map(t_data *data);
void	free_split(char **line, int code, t_data *data);

//Parsing and inicialization
void	map_loading(t_data *data, int fd, int index);

//Generate the list of points and draw them
void	map_to_point(t_data *data);
void	bresnham(t_data *data, t_point a, t_point b);
void	ft_draw_image_to_grid(t_data *data);

//Free and close
void	free_split(char **line, int code, t_data *data);
int		ft_close_fdf(void *data);



#endif
