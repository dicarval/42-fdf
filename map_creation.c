/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:49:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/19 17:29:20 by dicarval         ###   ########.fr       */
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

void	screen_dimensions (t_point point, t_data *data)
{

}

void	map_to_point(t_data *data)
{
	int	y;
	int	x;

	data->point_map = malloc(sizeof(t_point *) * data->height);
	y = 0;
	while (data->map_content[y++])
	{
		x = 0;
		data->point_map = malloc(sizeof(t_point *) * data->width);
		while (x < data->width)
		{
			data->point_map[y][x] = init_point(y, x, data->map_content[y][x]);
			screen_dimensions(data->point_map[y][x], data);
			x++;
		}
	}
}
