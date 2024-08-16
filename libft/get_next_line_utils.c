/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:59:54 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/28 14:29:37 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_content(t_list **lnklist, t_list *char_n_used)
{
	t_list	*tmp;
	t_list	*current;

	if (*lnklist == NULL)
		return ;
	current = *lnklist;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->buf);
		free(tmp);
	}
	*lnklist = NULL;
	if (char_n_used->buf[0] != '\0')
		*lnklist = char_n_used;
	else
	{
		free(char_n_used->buf);
		free(char_n_used);
	}
}

size_t	list_len(t_list *lnklist)
{
	size_t	line_len;
	int		i;

	line_len = 0;
	if (lnklist == NULL)
		return (0);
	while (lnklist != NULL)
	{
		i = 0;
		while (lnklist->buf[i] != '\0')
		{
			if (lnklist->buf[i] == '\n')
			{
				return (++line_len);
			}
			i++;
			line_len++;
		}
		lnklist = lnklist->next;
	}
	return (line_len);
}

int	end_line(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] != '\0')
		{
			if (list->buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = lstlast(*lst);
		last->next = new;
	}
}
