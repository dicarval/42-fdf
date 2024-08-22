/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:49:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/22 16:05:17 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	init_point(int y, int x, int z)
{
	t_point point;

	point.y = y;
	point.x = x;
	point.z = z;
	return (point);
}

t_point	isometric_for_scale(t_point a, t_data *data)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = ((temp_x - temp_y) * \
		cos(data->angle_x)) * data->size_grid;
	a.y = ((-(a.z) / data->z_adapted + (temp_x + temp_y) * \
	sin(data->angle_y))) * data->size_grid;
	if (data->min_z < 0)
		a.z = a.z - data->min_z + 1;
	return (a);
}

void	limits_finder(t_point point, t_data *data)
{
	int	x;
	int	y;

	if (data->max_z - data->min_z > 100)
		data->z_adapted = 10;
	if (data->max_z - data->min_z > 1000)
		data->z_adapted = 100;
	point = isometric_for_scale(point, data);
	x = point.x;
	y = point.y;
	if (x < data->screen.min_x && x < 0)
		data->screen.min_x = x;
	if (y < data->screen.min_y && y < 0)
		data->screen.min_y = y;
	if (!data->screen.max_x || x > data->screen.max_x)
		data->screen.max_x = x;
	if (!data->screen.max_y || y > data->screen.max_y)
		data->screen.max_y = y;
}

void	map_to_point(t_data *data)
{
	int	y;
	int	x;

	data->point_map = malloc(sizeof(t_point *) * data->height);
	y = 0;
	while (data->map_content[y])
	{
		x = 0;
		data->point_map = malloc(sizeof(t_point *) * data->width);
		while (x < data->width)
		{
			data->point_map[y][x] = init_point(y, x, data->map_content[y][x]);
			limits_finder(data->point_map[y][x], data);
			x++;
		}
		y++;
	}
}
