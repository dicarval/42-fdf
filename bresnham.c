/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresnham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:50:02 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/22 18:00:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	compare(int a, int b)
{
	int	ret;

	if (a < b)
		ret = 1;
	else
		ret = -1;
	return (ret);
}

t_param	*init_param(t_point a, t_point b)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
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
		my_mlx_pixel_put(data, a.x, a.y, percent_to_color);
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
}
