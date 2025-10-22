/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:48:20 by ttas              #+#    #+#             */
/*   Updated: 2025/10/20 21:10:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_parse	*init_parse(t_parse *parse)
{
	parse = malloc(sizeof(t_parse));
	parse->texture = malloc(sizeof(t_texture));
	parse->color[0][0] = -1;
	parse->color[0][1] = -1;
	parse->color[0][2] = -1;
	parse->color[1][0] = -1;
	parse->color[1][1] = -1;
	parse->color[1][2] = -1;
	parse->nb_textures = 0;
	parse->nb_colors = 0;
	return (parse);
}
