/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:20:35 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/16 15:08:07 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_max_min_z(t_data *data, int nb)
{
	if (!data->max_z || nb > data->max_z)
		data-> max_z = nb;
	if (!data->min_z || nb < data->min_z)
		data-> min_z = nb;
}

int	*split_atoi(t_data *data, char *line)
{
	char	**split_chars;
	int		*int_array;
	int		i;

	i = 0;
	split_chars = ft_split(line, ' ');
	int_array = malloc(sizeof(int) * data->nb_colls);
	while (split_chars[i++])
	{
		int_array[i] = ft_atoi(split_chars[i]);
		free(split_chars[i]);
	}
	return (int_array);
}

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
	else
		data->map_content[index] = (int *) line;
	free(line);
}
