/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:50:34 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/03 17:39:41 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(t_data *data, int z)
{
	if (data->min_z < 0 && z > 0)
		z = z - data->min_z;
	if (data->min_z < 0 && z < 0)
		z = z + data->min_z;
	data->p_rgb = z / (data->range_z / data->z_adapted);
	if (data->p_rgb = 1)
		data->color = 0x00FF0000;
	if (data->p_rgb = -1)
		data->color = 0x000000FF;

}
