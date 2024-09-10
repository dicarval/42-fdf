/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:10:52 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/10 15:11:50 by dicarval         ###   ########.fr       */
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
