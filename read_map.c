/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:20:35 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/14 11:54:07 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_loading(t_data *data, int fd, int index)
{
	char	*line;

	line = get_next_line(fd);
	data->nb_lines++;
	if (line)
		map_loading(data, fd, index + 1);
	else
		data->map_content = malloc(sizeof(int *) * data->nb_lines);
	if (line)
		data->map_content[index] = split_atoi(data, line);

}
