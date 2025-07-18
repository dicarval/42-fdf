/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:23:51 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/12 13:45:15 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *c)
{
	int	i;

	i = 0;
	if (c)
	{
		while (c[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*str;

	lens1 = ft_strlen_gnl(s1);
	lens2 = ft_strlen_gnl(s2);
	str = (char *)malloc(lens1 + lens2 + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (i++ < (lens1 -1))
		str[i] = s1[i];
	while (j++ < (lens2 - 1))
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	if (s1)
		free (s1);
	return (str);
}

int	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_cleanread(char *actual_line, char *buffer_content)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = ft_newline(actual_line);
	if (flag != -1)
	{
		actual_line [flag + 1] = '\0';
		flag = ft_newline (buffer_content);
		flag++;
		while (buffer_content[flag])
			buffer_content[i++] = buffer_content[flag++];
	}
	while (i < BUFFER_SIZE)
		buffer_content[i++] = '\0';
	return (actual_line);
}
