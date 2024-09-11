/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:53:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/11 11:59:13 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_fail(t_data *data)
{
	int	i;

	i = -1;
	write(2, "Malloc failed\n", 14);
	if (data->map_content)
	{
		if (data->map_content[0])
		{
			while (data->map_content[++i])
				free(data->map_content[i]);
		}
		free(data->map_content);
	}
	i = -1;
	if (data->point_map)
	{
		if (data->point_map[0])
		{
			while (data->point_map[++i])
				free(data->point_map[i]);
		}
		free(data->point_map);
	}
	ft_close_fdf(data);
}

void	free_mlx(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_content && data->map_content[i])
	{
		free(data->map_content[i]);
		free(data->point_map[i]);
		i++;
	}
	free(data->map_content);
	free(data->point_map);
	data->map_content = NULL;
	data->point_map = NULL;
}

int	ft_close_fdf(void *data)
{
	free_map((t_data *) data);
	free_mlx((t_data *) data);
	exit(0);
	return (0);
}

void	free_split(char **charct, int code, t_data *data)
{
	int	i;

	if (code == 1)
	{
		i = 0;
		while (charct[i])
			free(charct[i++]);
		free(charct);
		ft_close_fdf(data);
	}
	if (code == 2)
	{
		i = 0;
		while (charct[i])
			free(charct[i++]);
		free(charct);
	}
}
