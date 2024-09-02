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
		data->range.max_y /= 3;
		data->range.max_x /= 3;
		data->size_grid /= 3;
	}
	data->x_pos = W_WIDTH / 2 \
		- data->range.max_x / 4;
	data->y_pos = W_HEIGHT / 3 \
		- data->range.max_y / 3;
}

void	smaller_case(t_data *data)
{
	while ((data->range.max_x < W_WIDTH / 5 \
	|| data->range.max_x < W_HEIGHT /5))
	{
		data->range.max_y *= 3;
		data->range.max_x *= 3;
		data->size_grid *= 3;
	}
	data->x_pos = W_WIDTH / 2 \
		- data->range.max_x / 4;
	data->y_pos = W_HEIGHT / 3 \
		- data->range.max_y / 3;
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
}
