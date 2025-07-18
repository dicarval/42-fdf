/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:50:02 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/12 17:28:48 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < W_WIDTH) && (y >= 0 && y < W_HEIGHT))
	{
		dst = data->img.addr + (y * data->img.line_len + \
		x * (data->img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static int	color(t_data *data, int z)
{
	z *= data->z_adapted;
	if (data->min_z < 0)
		z -= data->min_z;
	data->p_rgb = (float)z / (float)data->range_z;
	if (data->p_rgb <= 1 && data->p_rgb >= 0.9)
		data->color = RED;
	else if (data->p_rgb < 0.9 && data->p_rgb >= 0.8)
		data->color = ORANGE;
	else if (data->p_rgb < 0.8 && data->p_rgb >= 0.6)
		data->color = Y_ORANGE;
	else if (data->p_rgb < 0.6 && data->p_rgb >= 0.4)
		data->color = YELLOW;
	else if (data->p_rgb < 0.4 && data->p_rgb >= 0.2)
		data->color = YELLOW_G;
	else if (data->p_rgb < 0.2 && data->p_rgb >= 0.1)
		data->color = Y_GREEN;
	else if (data->p_rgb < 0.1 && data->p_rgb >= 0.05)
		data->color = GREEN;
	else if (data->p_rgb < 0.05 && data->p_rgb >= 0.02)
		data->color = GREEN_B;
	else if (data->p_rgb < 0.02 && data->p_rgb >= 0.01)
		data->color = G_BLUE;
	else if (data->p_rgb < 0.01 && data->p_rgb >= 0)
		data->color = BLUE;
	return (data->color);
}

static int	compare(int a, int b)
{
	int	ret;

	if (a < b)
		ret = 1;
	else
		ret = -1;
	return (ret);
}

static t_param	init_param(t_point a, t_point b)
{
	t_param	param;

	param.dx = abs(b.x - a.x);
	param.sx = compare(a.x, b.x);
	param.dy = -abs(b.y - a.y);
	param.sy = compare(a.y, b.y);
	param.err = param.dx + param.dy;
	return (param);
}

void	bresnham(t_data *data, t_point a, t_point b)
{
	t_param	param;

	param = init_param(a, b);
	while (1)
	{
		my_mlx_pixel_put(data, a.x, a.y, color(data, a.z));
		if (a.x == b.x && a.y == b.y)
			break ;
		param.e2 = 2 * param.err;
		if (param.e2 >= param.dy)
		{
			param.err += param.dy;
			a.x += param.sx;
		}
		if (param.e2 <= param.dx)
		{
			param.err += param.dx;
			a.y += param.sy;
		}
	}
}
