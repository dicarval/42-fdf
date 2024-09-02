/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:43:52 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/02 17:27:58 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_out_img(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= W_WIDTH)
	{
		j = -1;
		while (++j <= W_HEIGHT)
			my_mlx_pixel_put(data, i, j, 0x00000000);
	}
	data->size_grid /= 1.5;
}

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

	p.z = p.z / data->z_adapted;
	p.y *= data->size_grid;
	p.x *= data->size_grid;
	iso(&p.x, &p.y, p.z, data->def_angle);
	p.y += data->y_pos;
	p.x += data->x_pos;
	return (p);
}

void	draw_image_to_grid(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->height - 1)
	{
		x = -1;
		while (++x < data->width - 1)
		{
			if (x < data->width - 2)
				bresnham(data, projection((data->point_map)[y][x], data), \
				projection((data->point_map)[y][x + 1], data));
			if (y < data->height - 2)
				bresnham(data, projection((data->point_map)[y][x], data), \
				projection((data->point_map)[y + 1][x], data));
		}
	}
	if ((projection((data->point_map)[y - 1][x - 1], data)).x > W_WIDTH \
		|| (projection((data->point_map)[y - 1][x - 1], data)).y > W_HEIGHT)
	{
		zoom_out_img(data);
		draw_image_to_grid(data);
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}
