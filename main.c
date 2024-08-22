/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:34:59 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/22 16:05:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_cross_press(t_data *data)
{
		mlx_destroy_image(data->mlx, data->img.mlx_img);
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
}

int	handle_esc_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img.mlx_img);
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return (0);
}
void	ft_set_variables(t_data *data)
{
	data->size_grid = 10;
	data->angle_y = DEFAULT_ANG;
	data->angle_x = DEFAULT_ANG;
	data->def_angle = DEFAULT_ANG;
	data->z_adapted = 1;
	data->screen.max_x = 0;
	data->screen.min_x = 0;
	data->screen.max_y = 0;
	data->screen.min_y = 0;
	data->max_z = 0;
	data->min_z = 0;
	data->x_pos = 0;
	data->y_pos = 0;
}

void	map_config(t_data *data)
{
	int	fd;

	fd = check_map(data);
	ft_set_variables(data);
	map_loading(data, fd, 0);
	map_to_point(data);
	data->img.mlx_img = \
		mlx_new_image(data->mlx, data->screen.max_x, data->screen.max_y);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, \
		&data->img.bpp, &data->img.line_len, &data->img.endian);
	data->win = mlx_new_window(data->mlx, \
		WINDOW_WIDTH, WINDOW_HEIGHT, "FdF - DICARVAL");
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_esc_press, &data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, &handle_cross_press, &data);
	ft_draw_image_to_grid(data);
}

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc = 2)
	{
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (MLX_ERROR);
		data.map_num = 1;
		data.max_argv = 0;
		while (argv[data.max_argv] != NULL)
			data.max_argv++;
		data.map_file = argv;
		map_config(&data);
		mlx_loop(data.mlx);
	}
	else
		perror("Number of arguments isn't correct\n");
	return (0);
}
