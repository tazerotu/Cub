/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:31:34 by marvin            #+#    #+#             */
/*   Updated: 2025/10/15 11:25:47 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

t_parse	*set_player_pos(t_parse *parse, int x, int y, char dir)
{
	parse->pos_player.x = x;
	parse->pos_player.y = y;
	parse->pos_player.dir = dir;
	return (parse);
}

void	find_player_pos(t_parse *parse)
{
	int	found;
	int	y;
	int	x;

	y = 0;
	found = 0;
	while (parse->floodfill[y])
	{
		x = 0;
		while (parse->floodfill[y][x])
		{
			if (is_player_char(parse->floodfill[y][x]))
			{
				if (found)
					error_message(ERROR_CLOSED, "Multiple players found");
				set_player_pos(parse, x, y, parse->floodfill[y][x]);
				found = 1;
			}
			x++;
		}
		y++;
	}
	if (!found)
		error_message(ERROR_CLOSED, "No player position found");
}

void	floodfill_check_closed(t_parse *parse, int x, int y)
{
	if (x < 0 || y < 0 || !parse->floodfill[y]
		|| x >= (int)ft_strlen(parse->floodfill[y]))
		error_message(ERROR_CLOSED, "Map not closed (out of bounds)");
	if (parse->floodfill[y][x] == '1' || parse->floodfill[y][x] == 'F')
		return ;
	if (parse->floodfill[y][x] == ' ')
		error_message(ERROR_CLOSED, "Map not closed (space found inside map)");
	if (parse->floodfill[y][x] == '0' || is_player_char(parse->floodfill[y][x]))
	{
		parse->floodfill[y][x] = 'F';
		floodfill_check_closed(parse, x + 1, y);
		floodfill_check_closed(parse, x - 1, y);
		floodfill_check_closed(parse, x, y + 1);
		floodfill_check_closed(parse, x, y - 1);
	}
}
