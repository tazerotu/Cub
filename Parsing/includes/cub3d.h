/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 08:56:23 by ttas              #+#    #+#             */
/*   Updated: 2025/09/09 09:45:42 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

// Error handling
# define ERROR_MEMORY -1001
# define ERROR_TEXTURE -1011
# define ERROR_IDENTIFIER -1012
# define ERROR_FD -1013
# define ERROR_ARGS -1014
# define ERROR_PATH -1015
# define ERROR_COLOR -1021
# define ERROR_CLOSED -1041
# define ERROR_CHARACTER -1042

// Struct
typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
}	t_texture;

typedef struct s_parse
{
	int			fd_map;
	t_texture	*texture;
	char		**map;
	char		**floodfill;
	int			color[2][3];	// [0] = floor, [1] = ceiling
}	t_parse;

typedef struct s_tex_parse
{
	int			used[4];
	int			count;
	int			type;
	int			i;
}	t_tex_parse;

// Functions

// Setup
t_parse	*init_parse(t_parse *parse);

// Error
void	error_message(int code, char *msg);

// Free
void	free_parse(t_parse *parse);

// Utils
int		has_non_whitespace(const char *str);

// Parse
t_parse	*parse_args(int argc, char **argv, t_parse *parse);
int		parse_texture(t_parse *parse);
int		parse_color(t_parse *parse);

// Parse Utils
	// Texture
void	texture_read_line(t_parse *parse, char **paths,
			char *line);
int		texture_path(char *line);
void	check_remaining_lines(char **buffer, int fd);

	// Color

#endif