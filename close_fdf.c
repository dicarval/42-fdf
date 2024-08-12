/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:09 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/12 15:29:26 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
void	free_map(t_data *data)
{
	int i;

	i = 0;
	while (data->map_file && data->map_file[i++])
	{
		free(data->map_file[i]);
		free(data->point_map[i]);
	}
	free(data->map_file);
	free(data->point_map);
	data->map_file = NULL;
	data->point_map = NULL;
}

int	ft_close_fdf(t_data *data)
{
	free_map(data);
	free_mlx(data);
	exit(0);
	return (0);
}
