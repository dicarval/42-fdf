/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:43:52 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/04 18:16:38 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom_adjust(t_data *data, int y, int x)
{
	int	i;
	int	j;
	t_point temp;
	t_point temp00;

	temp = projection((data->point_map)[y - 1][x - 1], data);
	temp00 = projection((data->point_map)[0][0], data);
	if ((temp.x > W_WIDTH || temp.y > W_HEIGHT) \
		|| ((temp.y - temp00.y) < (W_HEIGHT / 2)))
	{
		i = -1;
		while (++i <= W_WIDTH)
		{
			j = -1;
			while (++j <= W_HEIGHT)
				my_mlx_pixel_put(data, i, j, 0x00000000);
		}
		if (temp.x > W_WIDTH || temp.y > W_HEIGHT)
			data->size_grid /= 1.4;
		else
			data->size_grid *= 1.5;
		return (1);
	}
	return (0);
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
		while (++x < data->width)
		{
			if (x < data->width - 1)
				bresnham(data, projection((data->point_map)[y][x], data), \
				projection((data->point_map)[y][x + 1], data));
			if (y < data->height - 2)
				bresnham(data, projection((data->point_map)[y][x], data), \
				projection((data->point_map)[y + 1][x], data));
		}
	}
	if ((zoom_adjust(data, y, x)) == 1)
	{
		draw_image_to_grid(data);
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}
