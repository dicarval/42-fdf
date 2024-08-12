/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:34:59 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/12 18:37:48 by dicarval         ###   ########.fr       */
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
void	set_variables

void	map_config(t_data *data)
{
	int	fd;

	fd = check_map(data);
	set_variables(t_data *data);



	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_esc_press, &data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, &handle_cross_press, &data);



}

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc >= 2)
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
		perror("Not enough arguments\n");
	return (0);
}
