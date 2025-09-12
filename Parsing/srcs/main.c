/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:15:21 by ttas              #+#    #+#             */
/*   Updated: 2025/09/09 09:47:02 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_parse	*parse;

	parse = NULL;
	parse = init_parse(parse);
	parse = parse_args(argc, argv, parse);
	parse_texture(parse);
	printf("North texture: %s\n", parse->texture->north);
	printf("South texture: %s\n", parse->texture->south);
	printf("East texture: %s\n", parse->texture->east);
	printf("West texture: %s\n\n", parse->texture->west);
	parse_color(parse);
	printf("Floor color: R=%d, G=%d, B=%d\n", parse->color[0][0], parse->color[0][1], parse->color[0][2]);
	printf("Ceiling color: R=%d, G=%d, B=%d\n\n", parse->color[1][0], parse->color[1][1], parse->color[1][2]);
	// parse_map(parse); // to do
	free_parse(parse);
	return (0);
}
