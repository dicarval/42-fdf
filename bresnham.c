/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresnham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:50:02 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/02 17:29:05 by dicarval         ###   ########.fr       */
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

static int	compare(int a, int b)
{
	int	ret;

	if (a < b)
		ret = 1;
	else
		ret = -1;
	return (ret);
}

static t_param	*init_param(t_point a, t_point b)
{
	t_param	*param;

	param = malloc(sizeof((t_param *) + 1));
	if (!param)
		return (NULL);
	param->dx = abs(b.x - a.x);
	param->sx = compare(a.x, b.x);
	param->dy = -abs(b.y - a.y);
	param->sy = compare(a.y, b.y);
	param->err = param->dx + param->dy;
	return (param);
}

void	bresnham(t_data *data, t_point a, t_point b)
{
	t_param	*param;

	param = init_param(a, b);
	while (1)
	{
		my_mlx_pixel_put(data, a.x, a.y, 0xFFFFFF);
		if (a.x == b.x && a.y == b.y)
			break ;
		param->e2 = 2 * param->err;
		if (param->e2 >= param->dy)
		{
			param->err += param->dy;
			a.x += param->sx;
		}
		if (param->e2 <= param->dx)
		{
			param->err += param->dx;
			a.y += param->sy;
		}
	}
	free(param);
}
