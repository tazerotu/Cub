/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:37:41 by ttas              #+#    #+#             */
/*   Updated: 2025/10/09 14:38:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	lst_to_char(t_parse *parse, t_map *lst)
{
	t_map	*tmp;
	int		line;

	tmp = lst;
	line = lstmap_size(tmp);
	parse->floodfill = malloc(sizeof(char *) * (line + 1)); 
	parse->map = malloc(sizeof(char *) * (line + 1));
	if (!parse->floodfill || !parse->map)
		error_message(ERROR_MEMORY, "Malloc failed");
	tmp = lst;
	line = 0;
	while (tmp)
	{
		parse->floodfill[line] = ft_strdup(tmp->map);
		parse->map[line] = ft_strdup(tmp->map);
		line++;
		tmp = tmp->next;
	}
	parse->floodfill[line] = '\0';
	parse->map[line] = '\0';
}

int	parse_map(t_parse *parse)
{
	t_map	*lst_map;
	t_map	*tmp;
	char	*line;
	int		i;

	i = 0;
	lst_map = NULL;
	line = get_next_line(parse->fd_map);
	if (!line)
		error_message(ERROR_MAP, "Empty map");
	while (line)
	{
		if (i++ == 0)
			lst_map = ft_lstnew_map(line);
		else if (*line != '\0')
			ft_lst_addback_map(&lst_map, ft_lstnew_map(line));
		free(line);
		line = get_next_line(parse->fd_map);
	}
	tmp = lst_map;
	close(parse->fd_map);
	lst_to_char(parse, tmp);
	free_lst(lst_map);
	// floodfill(parse, 6, 3);
	return (0);
}
// while (tmp)
// {
// 	printf("line %d: %s", tmp->line, tmp->map);
// 	tmp = tmp->next;
// }
// printf("\n");
