/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:10:52 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/12 15:38:30 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	strcmp_fdf(char *map_name)
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
	while (map_name[i] != '\0')
	{
		if (map_name[i++] != fdf[j++])
			return (0);
	}
	return (1);
}

void	int_checker(t_data *data, char **temp, char *line, int line_len)
{
	int	i;
	long *nb;

	i = 0;
	nb = malloc(sizeof(long) * line_len);
	if (!nb)
		malloc_fail(data);
	while (i < line_len)
	{
		nb[i] = ft_atoi(temp[i]);
		if (nb[i] > INT_MAX || nb[i] < INT_MIN)
		{
			free(line);
			free(nb);
			write(2, "The map file has a number out of int range\n", 43);
			free_split(temp, 1, data);
		}
		i++;
	}
	free(nb);
}
