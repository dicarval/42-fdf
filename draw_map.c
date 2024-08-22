/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:43:52 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/21 15:20:58 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_ypixel(t_data *data, int y, int x)
{

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
				set_xpixel(data, y, x);
			if (y < data->height - 1)
				set_ypixel(data, y, x);
			x++;
		}
		y++;
	}
}
