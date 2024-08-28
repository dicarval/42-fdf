/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:49:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/28 17:25:02 by dicarval         ###   ########.fr       */
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

/* static t_point	isometric_for_scale(t_point a, t_data *data)
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
} */

static void	range_to_zoom(t_data *data)
{
	int	av_width;
	int	av_height;

/* 	ft_printf("%d\n", data->range_x);
	ft_printf("%d\n", data->range.max_x);
	ft_printf("%d\n", data->range.min_x); */
	data->range_x = data->range.max_x - data->range.min_x;
	data->range_y = data->range.max_y - data->range.min_y;
	av_width = WINDOW_WIDTH;
	av_height = WINDOW_HEIGHT;
	if (data->range_x > 0 && data->range_y > 0)
	{
		av_width = WINDOW_WIDTH - data->range_x;
		av_height = WINDOW_HEIGHT - data->range_y;
	}
	data->zoom = (av_width + av_height) / 80;
	data->x_pos = (WINDOW_WIDTH / 2) - (data->range_x * 7);
	data->y_pos = (WINDOW_HEIGHT / 2) - (data->range_y * 30);
	ft_printf("%d\n", data->x_pos);
	ft_printf("%d\n", data->y_pos);
}

static void	limits_finder(t_point point, t_data *data)
{
	int	x;
	int	y;

	if (data->max_z - data->min_z > 100)
		data->z_adapted = 10;
	if (data->max_z - data->min_z > 1000)
		data->z_adapted = 100;
	//point = projection(point, data);
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
	ft_printf("%d\n", data->range.min_x);
	ft_printf("%d\n", data->range.max_x);
	ft_printf("%d\n", data->range.min_y);
	ft_printf("%d\n", data->range.max_y);
	range_to_zoom(data);
}
