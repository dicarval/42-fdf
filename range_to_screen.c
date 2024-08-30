/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_to_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:20:32 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/29 18:25:05 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bigger_case(t_data *data)
{
	while ((data->range.max_x > W_WIDTH || \
		data->range.max_x > W_HEIGHT))
	{
		data->range.max_y /= 2;
		data->range.max_x /= 2;
		data->x_pos = abs(data->x_pos / 2);
		data->y_pos = abs(data->y_pos / 2);
		data->size_grid /= 2;
	}
}

void	smaller_case(t_data *data)
{
	while ((data->range.max_x < W_WIDTH / 5 \
	|| data->range.max_x < W_HEIGHT / 5))
	{
		data->range.max_y *= 3;
		data->range.max_x *= 3;
		data->x_pos = abs(data->x_pos * 3);
		data->y_pos = abs(data->y_pos * 3);
		data->size_grid *= 3;
	}
}

void	range_to_zoom(t_data *data)
{
	int	avb_wth;
	int	avb_hth;

	avb_wth = W_WIDTH - data->range.max_x;
	avb_hth = W_HEIGHT - data->range.max_y;
	if (avb_wth < 0 || avb_hth < 0)
		bigger_case(data);
	else
		smaller_case(data);
	data->x_pos = W_WIDTH / 2 \
		- data->range.max_x / 2 + data->x_pos;
	data->y_pos = W_HEIGHT / 2 \
		- data->range.max_y / 2 + data->y_pos;
	data->range.max_x = W_WIDTH;
	data->range.max_y = W_HEIGHT;
	ft_printf("%d\n", data->range.max_x);
	ft_printf("%d\n", data->range.max_y);
	ft_printf("%d\n", data->x_pos);
	ft_printf("%d\n", data->y_pos);
	ft_printf("%d\n", data->zoom);
	ft_printf("%d\n", data->size_grid);
}
