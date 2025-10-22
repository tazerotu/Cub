/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:37:39 by ttas              #+#    #+#             */
/*   Updated: 2025/10/21 09:31:26 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_component(char **str)
{
	int		val;
	char	*substr;
	int		len;

	len = 0;
	while (**str && (**str == ' ' || **str == ','))
		(*str)++;
	while ((*str)[len] && (*str)[len] >= '0' && (*str)[len] <= '9')
		len++;
	if (len == 0)
		error_message(ERROR_COLOR, "Missing color component");
	substr = ft_substr(*str, 0, len);
	val = ft_atoi(substr);
	free(substr);
	if (val < 0 || val > 255)
		error_message(ERROR_COLOR, "Value out of range (0-255)");
	*str += len;
	return (val);
}

t_parse	*parse_color_line(t_parse *parse, char *line)
{
	int		type;
	char	*ptr;

	type = -1;
	ptr = line;
	if (ft_strlen(line) < 2)
		error_message(ERROR_IDENTIFIER, "Invalid color identifier");
	if (ft_strncmp(line, "F ", 2) == 0)
		type = 0;
	else if (ft_strncmp(line, "C ", 2) == 0)
		type = 1;
	else if (type == -1)
		error_message(ERROR_IDENTIFIER, "Invalid color identifier");
	while (*ptr && *ptr != ' ')
		ptr++;
	if (!*ptr)
		error_message(ERROR_COLOR, "Missing color components");
	parse->color[type][0] = parse_component(&ptr);
	parse->color[type][1] = parse_component(&ptr);
	parse->color[type][2] = parse_component(&ptr);
	return (parse);
}

// // Skips new lines
// char	*skip_nl(t_parse *parse, char *line)
// {
// 	while (line && *line == '\n')
// 	{
// 		free(line);
// 		line = get_next_line(parse->fd_map);
// 	}
// 	return (line);
// }

// // Helper to parse and validate a single color component (0-255)
// // Line : 47
// // printf("Parsed component: %d\n", val);
// static int	parse_component(char **str)
// {
// 	int		val;
// 	char	*substr;
// 	int		len;

// 	len = 0;
// 	while (**str && (**str == ' ' || **str == ','))
// 		(*str)++;
// 	while ((*str)[len] && (*str)[len] >= '0' && (*str)[len] <= '9')
// 		len++;
// 	if (len == 0)
// 		error_message(ERROR_COLOR, "Missing color component");
// 	substr = ft_substr(*str, 0, len);
// 	val = ft_atoi(substr);
// 	free(substr);
// 	if (val < 0 || val > 255)
// 		error_message(ERROR_COLOR, "Value out of range (0-255)");
// 	*str += len;
// 	return (val);
// }

// // Converts color line to int array, validates identifier and range
// // Line : 58
// // printf("Converting color for type %d from line: %s\n", type, line);
// void	convert_color(t_parse *parse, char *line, int type)
// {
// 	if (type < 0 || type > 1)
// 		return ;
// 	while (*line && *line != ' ')
// 		line++;
// 	if (!*line)
// 		return ;
// 	parse->color[type][0] = parse_component(&line);
// 	parse->color[type][1] = parse_component(&line);
// 	parse->color[type][2] = parse_component(&line);
// 	if (parse->color[type][0] == -1 || parse->color[type][1] == -1
// 		|| parse->color[type][2] == -1)
// 		return ;
// }

// // Reads and parses color lines, ensures only 2 identifiers before map.
// // Line : 88
// // printf("Processed color line, moving to next.\n");
// // Line : 94
// // printf("F: %d,%d,%d | C: %d,%d,%d\n", 
// // parse->color[0][0], parse->color[0][1], 
// // parse->color[0][2], parse->color[1][0], 
// // parse->color[1][1], parse->color[1][2]);
// int	parse_color(t_parse *parse)
// {
// 	char	*line;
// 	int		i;

// 	i = -1;
// 	line = get_next_line(parse->fd_map);
// 	while (++i < 2)
// 	{
// 		line = skip_nl(parse, line);
// 		if (!line)
// 			break ;
// 		if (*line == 'F')
// 			convert_color(parse, line, 0);
// 		else if (*line == 'C')
// 			convert_color(parse, line, 1);
// 		else if (*line && *line != '\n' && *line != ' ')
// 			break ;
// 		free(line);
// 		line = get_next_line(parse->fd_map);
// 	}
// 	if (line)
// 		free(line);
// 	return (0);
// }
