/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:36:46 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/12 12:29:27 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	check_empty_map(t_data *data, char *line)
{
	if (line == NULL)
	{
		perror("The map file is empty\n");
		ft_close_fdf(data);
	}
}
int	digit_check(t_data *data, char *line)
{
	char	**temp;
	int		i;
	int		line_len;

	if (!line)
		return (0);
	temp = ft_split(line, ' ');
	line_len = 0;
	while (temp[line_len])
	{
		i = 0;
		while (temp[line_len][i] && temp[line_len][i] != '\n')
		{
			if (temp[line_len][i] == '-' && i == 0)
				i++;
			if (!ft_isdigit(temp[line_len][i]))
				free_split(temp, 1, data);
			i++;
		}
		line_len++;
	}
	free_split(temp, 2, data);
	return (line_len);
}

int	check_digits_map(int fd, t_data *data)
{
	char	*line;
	int		line_len;
	int		line_len2;

	line = get_next_line(fd);
	check_empty_map(data, line);
	line_len = digit_check(data, line);
	free(line);
	while ((line = get_next_line(fd)))
	{
		line_len2 = digit_check(data, line);
		if (line_len != line_len2)
		{
			free(line);
			perror("The map isn't a square or a rectangule\n");
			ft_close_fdf(data);
		}
		free(line);
	}
	return(1);
}

int	check_map(t_data *data)
{
	int	fd;

	if (!strcmp_fdf(data->map_file[data->map_num]))
	{
		perror("The file is not a .fdf file\n");
		ft_close_fdf(data);
	}
	else
	{
		fd = open(data->map_file[data->map_num], O_RDONLY);
		if (fd == -1)
		{
			perror("The file is not in the directory\n");
			ft_close_fdf(data);
		}
		else if (check_digits_map(fd, data))
		{
			close (fd);
			fd = open(data->map_file[data->map_num], O_RDONLY);
		}
		return (fd);
	}
	return (0);
}
