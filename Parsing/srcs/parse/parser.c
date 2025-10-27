/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:05:10 by ttas              #+#    #+#             */
/*   Updated: 2025/10/27 10:28:57 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_texture(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "N ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "S ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "E ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "W ", 2) == 0)
		return (1);
	return (0);
}

int	is_color(char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

int	is_map_start(char *line)
{
	if (line && (*line == '1' || *line == '0' || *line == ' '))
		return (1);
	return (0);
}

void	parsing_error(t_parse *parse)
{
	if (parse->nb_textures != 4)
		error_message(ERROR_IDENTIFIER, "Missing texture identifier");
	if (parse->nb_colors != 2)
		error_message(ERROR_IDENTIFIER, "Missing color identifier");
	error_message(ERROR_MAP, "Invalid map format");
}

t_parse	*parser(t_parse *parse)
{
	char	*line;

	line = get_next_line(parse->fd_map);
	if (!line)
		return (NULL);
	while (line)
	{
		if (*line == '\n')
		{
			free(line);
			line = get_next_line(parse->fd_map);
		}
		if (is_texture(line))
			parse_texture_line(parse, line);
		else if (is_color(line))
			parse_color_line(parse, line);
		if (is_map_start(line))
			break ;
		free(line);
		line = get_next_line(parse->fd_map);
	}
	if (!line || parse->nb_textures != 4 || parse->nb_colors != 2)
		parsing_error(parse);
	parse_map(parse, line);
	return (parse);
}
