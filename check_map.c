/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:36:46 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/11 11:55:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	width_checker(t_data *data, char **temp, int line_len, char *line)
{
	int	i;

	i = 0;
	while (temp[line_len][i] && temp[line_len][i] != '\n')
	{
		if (temp[line_len][i] == ',')
			break ;
		if (temp[line_len][i] == '-' && i == 0)
			i++;
		if (!ft_isdigit(temp[line_len][i]))
		{
			write(2, "The map file has a non-digit character\n", 39);
			free(line);
			free_split(temp, 1, data);
		}
		i++;
	}
}

static void	check_empty_map(t_data *data, char *line)
{
	if (line == NULL)
	{
		write(2, "The map file is empty\n", 22);
		ft_close_fdf(data);
	}
}

static int	digit_check(t_data *data, char *line)
{
	char	**temp;
	int		line_len;

	if (!line)
		return (0);
	temp = ft_split(line, ' ');
	line_len = 0;
	while (temp[line_len])
	{
		width_checker(data, temp, line_len, line);
		line_len++;
	}
	if (temp[line_len - 1][0] == '\n')
		line_len--;
	free_split(temp, 2, data);
	return (line_len);
}

static int	check_digits_map(int fd, t_data *data)
{
	char	*line;
	int		line_len;
	int		line_len2;

	line = get_next_line(fd);
	check_empty_map(data, line);
	line_len = digit_check(data, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			line_len2 = digit_check(data, line);
		if (line_len != line_len2)
		{
			free(line);
			write(2, "Error: The map lines hasn't always the same lenght\n"\
			 , 51);
			ft_close_fdf(data);
		}
	}
	free(line);
	data->width = line_len;
	return (1);
}

int	check_map(t_data *data)
{
	int	fd;

	if (!strcmp_fdf(data->map_file[data->map_num]))
	{
		write(2, "The file is not a .fdf file\n", 28);
		ft_close_fdf(data);
	}
	else
	{
		fd = open(data->map_file[data->map_num], O_RDONLY);
		if (fd == -1)
		{
			write(2,"No file in the directory or it has no permissions\n", 50);
			ft_close_fdf(data);
		}
		else if (check_digits_map(fd, data))
		{
			close(fd);
			fd = open(data->map_file[data->map_num], O_RDONLY);
		}
		return (fd);
	}
	return (0);
}
