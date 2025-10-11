/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 08:53:21 by ttas              #+#    #+#             */
/*   Updated: 2025/10/06 11:18:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*ft_lstlast_map(t_map *lst_map)
{
	while (lst_map && lst_map->next)
		lst_map = lst_map->next;
	return (lst_map);
}

int	lstmap_size(t_map *lst_map)
{
	int	i;

	i = 0;
	while (lst_map)
	{
		lst_map = lst_map->next;
		i++;
	}
	return (i);
}

t_map	*ft_lstnew_map(char *map_line)
{
	t_map	*lst_map;

	lst_map = malloc(sizeof(t_map));
	if (!lst_map)
		return (NULL);
	lst_map->line = 0;
	lst_map->map = ft_strdup(map_line);
	lst_map->next = NULL;
	lst_map->prev = NULL;
	return (lst_map);
}

void	ft_lst_addback_map(t_map **lst_map, t_map *new_map)
{
	if (!new_map)
		return;
	if (*lst_map)
	{
		t_map *last = ft_lstlast_map(*lst_map);
		new_map->prev = last;
		new_map->line = last->line + 1;
		last->next = new_map;
	}
	else
		*lst_map = new_map;
}

void	free_lst(t_map *lst_map)
{
	t_map *tmp;

	while (lst_map && lst_map->prev)
		lst_map = lst_map->prev;
	while (lst_map)
	{
		tmp = lst_map->next;
		free(lst_map->map);
		free(lst_map);
		lst_map = tmp;
	}
}
