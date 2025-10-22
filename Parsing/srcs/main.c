/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:15:21 by ttas              #+#    #+#             */
/*   Updated: 2025/10/21 09:42:19 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
// Texture
printf("North texture: %s\n", parse->texture->north);
printf("South texture: %s\n", parse->texture->south);
printf("East texture: %s\n", parse->texture->east);
printf("West texture: %s\n\n", parse->texture->west);

// Color
printf("Floor color: R=%d, G=%d, B=%d\n", parse->color[0][0],
parse->color[0][1], parse->color[0][2]);
printf("Ceiling color: R=%d, G=%d, B=%d\n\n", parse->color[1][0],
parse->color[1][1], parse->color[1][2]);

// Player position
printf("Player position: x=%d, y=%d, dir=%c\n\n", parse->pos_player.x,
parse->pos_player.y, parse->pos_player.dir);

// Floodfill map
if (parse->map)
{
	for (int row = 0; parse->map[row]; row++)
	{
		for (int col = 0; parse->map[row][col]; col++)
		{
			printf("%c", parse->map[row][col]);
		}
	}
}
// printf("\n");
*/

// parse_texture(parse);
// parse_color(parse);
int	main(int argc, char **argv)
{
	t_parse	*parse;

	parse = NULL;
	parse = init_parse(parse);
	parse = parse_args(argc, argv, parse);
	parser(parse);
	find_player_pos(parse);
	floodfill_check_closed(parse, parse->pos_player.x, parse->pos_player.y);
	free_parse(parse);
	return (0);
}
