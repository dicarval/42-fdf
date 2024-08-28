/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:43:52 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/28 16:00:13 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(int *x, int *y, int z, double teta)
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
	t_point temp;

	temp = p;
	temp.y *= data->zoom;
	temp.x *= data->zoom;
	iso(&temp.x, &temp.y, temp.z, data->def_angle);
	temp.x += data->x_pos;
	temp.y += data->y_pos;
	return (temp);
}

void	ft_draw_image_to_grid(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height - 1)
	{
		x = 0;
		while (x < data->width - 1)
		{
			if (x < data->width - 2)
			{
				bresnham(data, projection((data->point_map)[y][x], data), \
				projection((data->point_map)[y][x + 1], data));
			}
			if (y < data->height - 2)
				bresnham(data, projection((data->point_map)[y][x], data), \
				projection((data->point_map)[y + 1][x], data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}
