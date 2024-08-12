/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:53:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/12 15:09:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	strcmp_fdf (char *map_name)
{
	int		i;
	int		j;
	char	*fdf;

	fdf = ".fdf";
	i = 0;
	j = 0;
	while (map_name[i] != '\0')
		i++;
	i -= 4;
	while (map_name[i++] != '\0')
	{
		if (map_name[i] != fdf[j++])
			return (0);
	}
	return (1);
}

void	free_split(char **line, int code, t_data data)
{
	int i;

	if (code == 1)
	{
		perror("The map file has a non-digit character\n");
		i = 0;
		while (line[i])
			free(line[i++]);
		free(line);
		ft_close_fdf(data);
	}
	if (code == 2)
	{
		i = 0;
		while (line[i])
			free(line[i++]);
		free(line);
	}
}
