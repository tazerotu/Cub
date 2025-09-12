/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:04:15 by ttas              #+#    #+#             */
/*   Updated: 2025/09/09 09:40:31 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
// === Ensure no extra identifiers exist ===
// static void	texture_extra_identifiers
// (t_parse *parse, char *line, char **buffer)
// {
// 	line = get_next_line_no_static(parse->fd_map, buffer);
// 	while (line)
// 	{
// 		if (*line == '\n')
// 		{
// 			free(line);
// 			line = get_next_line_no_static(parse->fd_map, buffer);
// 			continue ;
// 		}
// 		if (texture_path(line) != -1)
// 		{
// 			free(line);
// 			error_message(ERROR_IDENTIFIER,
// 				"More than 4 texture identifiers found.");
// 		}
// 		break ;
// 	}
// 	free(line);
// }

// static int	texture_set_type(char *line, int *used)
// {
// 	int	type;

// 	type = texture_path(line);
// 	if (type == -1)
// 		error_message(ERROR_IDENTIFIER, "Invalid texture identifier.");
// 	if (used[type])
// 		error_message(ERROR_IDENTIFIER, "Duplicate texture identifier.");
// 	return (type);
// }

// static char	*texture_skip_sw(char *line, int *i)
// {
// 	*i = 0;
// 	while (line[*i] && line[*i] != ' ')
// 		(*i)++;
// 	while (line[*i] == ' ')
// 		(*i)++;
// 	if (!line[*i] || !has_non_whitespace(&line[*i]))
// 		error_message(ERROR_PATH,
// 			"Missing or invalid texture path after identifier.");
// 	return (line);
// }

// // === Read lines until we have exactly 4 texture identifiers ===
// void	texture_read_line(t_parse *parse, char **paths, 
// 	char **buffer, char *line)
// {
// 	t_tex_parse tex_parse;

// 	ft_memset(tex_parse.used, 0, sizeof(tex_parse.used));
// 	tex_parse.count = 0;
// 	while (tex_parse.count < 4)
// 	{
// 		line = get_next_line_no_static(parse->fd_map, buffer);
// 		if (!line)
// 			error_message(ERROR_FD, "Unexpected end of file. (texture)");
// 		while (*line == '\n')
// 		{
// 			free(line);
// 			line = get_next_line_no_static(parse->fd_map, buffer);
// 			if (!line)
// 				error_message(ERROR_FD, "Unexpected end of file. (texture)");
// 		}
// 		tex_parse.type = texture_set_type(line, tex_parse.used);
// 		tex_parse.used[tex_parse.type] = 1;
// 		line = texture_skip_sw(line, &tex_parse.i);
// 		paths[tex_parse.type] = ft_substr(line, tex_parse.i, 
// 			ft_strlen(line) - tex_parse.i);
// 		free(line);
// 		tex_parse.count++;
// 	}
// 	// texture_extra_identifiers(parse, line, buffer);
// }
*/

static int	texture_set_type(char *line, int *used)
{
	int	type;

	type = texture_path(line);
	if (type == -1)
		error_message(ERROR_IDENTIFIER, "Invalid texture identifier.");
	if (used[type])
		error_message(ERROR_IDENTIFIER, "Duplicate texture identifier.");
	return (type);
}

static char	*texture_skip_sw(char *line, int *i)
{
	*i = 0;
	while (line[*i] && line[*i] != ' ')
		(*i)++;
	while (line[*i] == ' ')
		(*i)++;
	if (!line[*i] || !has_non_whitespace(&line[*i]))
		error_message(ERROR_PATH,
			"Missing or invalid texture path after identifier.");
	return (line);
}

// === Read lines until we have exactly 4 texture identifiers ===
// texture_extra_identifiers(parse, line);
void	texture_read_line(t_parse *parse, char **paths, char *line)
{
	t_tex_parse	tex_parse;

	ft_memset(tex_parse.used, 0, sizeof(tex_parse.used));
	tex_parse.count = 0;
	while (tex_parse.count < 4)
	{
		line = get_next_line(parse->fd_map);
		if (!line)
			error_message(ERROR_FD, "Unexpected end of file. (texture)");
		while (*line == '\n')
		{
			free(line);
			line = get_next_line(parse->fd_map);
			if (!line)
				error_message(ERROR_FD, "Unexpected end of file. (texture)");
		}
		tex_parse.type = texture_set_type(line, tex_parse.used);
		tex_parse.used[tex_parse.type] = 1;
		line = texture_skip_sw(line, &tex_parse.i);
		paths[tex_parse.type] = ft_substr(line, tex_parse.i,
				(ft_strlen(line) - tex_parse.i) - 1);
		free(line);
		tex_parse.count++;
	}
}
