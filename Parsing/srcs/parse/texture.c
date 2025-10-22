/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:37:26 by ttas              #+#    #+#             */
/*   Updated: 2025/10/21 09:40:59 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
	typedef struct s_texture 
	{
		char		*north;
		char		*south;
		char		*east;
		char		*west;
	} t_texture;


	typedef struct s_parse
	{
		int			fd_map;
		t_texture	texture;
		char		**map;
		char		**floodfill;
		char		floor[3];
		char		ceiling[3];
	} t_parse;
*/

// int	texture_path(char *line)
// {
// 	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "N ", 2) == 0)
// 		return (0);
// 	if (ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "S ", 2) == 0)
// 		return (1);
// 	if (ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "E ", 2) == 0)
// 		return (2);
// 	if (ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "W ", 2) == 0)
// 		return (3);
// 	return (-1);
// }

// static t_parse	*texture_set_path(t_parse *parse, char **paths)
// {
// 	parse->texture->north = ft_strdup(paths[0]);
// 	parse->texture->south = ft_strdup(paths[1]);
// 	parse->texture->east = ft_strdup(paths[2]);
// 	parse->texture->west = ft_strdup(paths[3]);
// 	return (parse);
// }

// printf("NO: %s\nSO: %s\nEA: %s\nWE: %s\n", parse->texture->north, 
//parse->texture->south, parse->texture->east, parse->texture->west);
// int	parse_texture(t_parse *parse)
// {
// 	char	*line;
// 	char	**paths;
// 	char	*buffer;
// 	int		i;

// 	i = -1;
// 	paths = ft_calloc(4, sizeof(char *));
// 	line = NULL;
// 	buffer = NULL;
// 	texture_read_line(parse, paths, &buffer, line);
// 	parse = texture_set_path(parse, paths);
// 	while (++i < 4)
// 		free(paths[i]);
// 	free(paths);
// 	free(buffer);
// 	if (line)
// 		free(line);
// 	return (0);
// }

// int	parse_texture(t_parse *parse)
// {
// 	char	*line;
// 	char	**paths;
// 	int		i;

// 	i = -1;
// 	paths = ft_calloc(4, sizeof(char *));
// 	line = NULL;
// 	texture_read_line(parse, paths, line);
// 	parse = texture_set_path(parse, paths);
// 	while (++i < 4)
// 		free(paths[i]);
// 	free(paths);
// 	if (line)
// 		free(line);
// 	return (0);
// }

static int	get_texture_type(char *line)
{
	int	type;

	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "N ", 2) == 0)
		type = 0;
	else if (ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "S ", 2) == 0)
		type = 1;
	else if (ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "E ", 2) == 0)
		type = 2;
	else if (ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "W ", 2) == 0)
		type = 3;
	else
		type = -1;
	return (type);
}

static void	set_texture_type(t_parse *parse, int type, char *path, int len)
{
	if (type == 0)
	{
		parse->texture->north = path;
		parse->texture->north[len - 1] = '\0';
	}
	else if (type == 1)
	{
		parse->texture->south = path;
		parse->texture->south[len - 1] = '\0';
	}
	else if (type == 2)
	{
		parse->texture->east = path;
		parse->texture->east[len - 1] = '\0';
	}
	else if (type == 3)
	{
		parse->texture->west = path;
		parse->texture->west[len - 1] = '\0';
	}
	return ;
}

t_parse	*parse_texture_line(t_parse *parse, char *line)
{
	int		type;
	char	*path;
	int		len;

	path = NULL;
	if (ft_strlen(line) < 3)
		error_message(ERROR_IDENTIFIER, "Invalid texture identifier");
	type = get_texture_type(line);
	if (type == -1)
		error_message(ERROR_IDENTIFIER, "Invalid texture identifier");
	while (line && *line != ' ')
		line++;
	path = ft_substr(line, 1, ft_strlen(line) - 1);
	len = ft_strlen(line) - 1;
	set_texture_type(parse, type, path, len);
	parse->nb_textures++;
	return (parse);
}
