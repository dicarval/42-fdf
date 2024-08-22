/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:43:52 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/22 16:34:44 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z, double teta)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(teta);
	*y = (previous_x + previous_y) * sin(teta) - z;
}

t_point	projection(t_point p, t_data *data)
{
	iso(&p.x, &p.y, p.z, data->def_angle);
	p.x += data->x_pos;
	p.y += data->y_pos;
	return (p);
}

void	ft_draw_image_to_grid(t_data *data)
{
	int	y;
	int	x;

	data->x_pos = (WINDOW_WIDTH / 2) - (data->width / 2);
	data->y_pos = (WINDOW_HEIGHT / 2) - (data->height / 2);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresnham(data, projection((data->point_map)[y][x], data), \
				projection((data->point_map)[y][x + 1], data));
			if (y < data->height - 1)
				bresnham(data, projection((data->point_map)[y][x], data), \
				projection((data->point_map)[y + 1][x], data));
			x++;
		}
		y++;
	}
}
