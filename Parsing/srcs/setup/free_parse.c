/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:22:09 by ttas              #+#    #+#             */
/*   Updated: 2025/09/09 09:32:39 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
	int		fd_map;
	char	**map;
	char	**floodfill;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	char	floor[3];
	char	ceiling[3];
	parse;
*/

void	free_parse_map(t_parse parse)
{
	int	i;

	i = -1;
	while (parse.map[++i])
		free(parse.map[i]);
	free(parse.map);
	i = -1;
	while (parse.floodfill[++i])
		free(parse.floodfill[i]);
	free(parse.floodfill);
}

void	free_parse_texture(t_texture *texture)
{
	free(texture->north);
	free(texture->south);
	free(texture->east);
	free(texture->west);
	free(texture);
}

void	free_parse(t_parse *parse)
{
	free_parse_texture(parse->texture);
	free(parse);
}
