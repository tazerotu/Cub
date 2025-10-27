/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:31:34 by marvin            #+#    #+#             */
/*   Updated: 2025/10/27 11:11:44 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_invalid_char(char c)
{
	if (!(c == '1' || c == '0' || c == 'F' || is_player_char(c)))
		return (1);
	else
		return (0);
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
		|| x >= (int)ft_strlen(parse->floodfill[y])
		|| is_invalid_char(parse->floodfill[y][x]) == 1)
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
