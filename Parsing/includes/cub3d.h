/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 08:56:23 by ttas              #+#    #+#             */
/*   Updated: 2025/10/21 09:14:33 by ttas             ###   ########.fr       */
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
# define ERROR_MAP -1043

# define MAP_WIDTH 80
# define MAP_HEIGHT 80

// Struct
typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
}	t_texture;

typedef struct s_map
{
	int				line;
	char			*map;
	struct s_map	*prev;
	struct s_map	*next;
}	t_map;

typedef struct s_pos
{
	int		x;
	int		y;
	char	dir;
}	t_pos;

typedef struct s_parse
{
	int			fd_map;
	t_texture	*texture;
	char		**map;
	char		**floodfill;
	t_map		*lst_map;
	t_pos		pos_player;
	int			color[2][3];	// [0] = floor, [1] = ceiling
	int			nb_textures;
	int			nb_colors;
}	t_parse;

typedef struct s_tex_parse
{
	int			used[4];
	int			count;
	int			type;
	int			i;
}	t_tex_parse;



typedef struct s_player
{
    double x, y;
    double angle;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    int color[2][3];    // [0] = floor, [1] = ceiling
    t_player player;
    int map[MAP_HEIGHT][MAP_WIDTH];
} t_game;

// Functions

// Setup
t_parse	*init_parse(t_parse *parse);

// Error
void	error_message(int code, char *msg);

// Free
void	free_parse(t_parse *parse);
void	free_lst(t_map *lst_map);

// Utils
int		has_non_whitespace(const char *str);
t_map	*ft_lstlast_map(t_map *lst_map);
t_map	*ft_lstnew_map(char *map_line);
void	ft_lst_addback_map(t_map **lst_map, t_map *new_map);
int		lstmap_size(t_map *lst_map);
void	find_player_pos(t_parse *parse);
void	floodfill_check_closed(t_parse *parse, int x, int y);

// Parse
t_parse	*parser(t_parse *parse);
t_parse	*parse_args(int argc, char **argv, t_parse *parse);
t_parse	*parse_texture_line(t_parse *parse, char *line);
t_parse	*parse_color_line(t_parse *parse, char *line);
// int		parse_texture(t_parse *parse);
// int		parse_color(t_parse *parse);
int		parse_map(t_parse *parse, char *line);
void	floodfill(t_parse *parse, int x, int y);

// Parse Utils
	// Texture
// void	texture_read_line(t_parse *parse, char **paths,
// 			char *line);
// int		texture_path(char *line);
// void	check_remaining_lines(char **buffer, int fd);

	// Color

//Raycasting
int is_wall(t_game *g, double x, double y);
void my_pixel_put(int line_len, int bpp, char *addr, int x, int y, int color);
int render(t_game *g);
int handle_key(int key, t_game *g);


#endif