/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:49:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/29 18:43:37 by dicarval         ###   ########.fr       */
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

static void	limits_finder(t_point point, t_data *data)
{
	int	x;
	int	y;

	if (data->max_z - data->min_z > 100)
		data->z_adapted = 5;
	if (data->max_z - data->min_z > 1000)
		data->z_adapted = 50;
	x = point.x;
	y = point.y;
	if (x < data->range.min_x && x < 0)
		data->range.min_x = x;
	if (y < data->range.min_y && y < 0)
		data->range.min_y = y;
	if (!data->range.max_x || x > data->range.max_x)
		data->range.max_x = x;
	if (!data->range.max_y || y > data->range.max_y)
		data->range.max_y = y;
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
		data->point_map[y] = malloc(sizeof(t_point) * data->width);
		while (x < data->width)
		{
			data->point_map[y][x] = init_point(y, x, data->map_content[y][x]);
			limits_finder(data->point_map[y][x], data);
			x++;
		}
		y++;
	}
	//range_to_zoom(data);
}
