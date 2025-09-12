/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:46:26 by ttas              #+#    #+#             */
/*   Updated: 2025/09/09 09:46:26 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_parse	*parse_args(int argc, char **argv, t_parse *parse)
{
	if (argc != 2)
		error_message(ERROR_ARGS,
			"Wrong amount of arguments\nuse ./Cub3d <path_to_map>");
	if (argv[1][0] == '\0')
		error_message(ERROR_ARGS, "No map given");
	if ((ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4)) != 0)
		error_message(ERROR_FD, "Invalid map file");
	parse->fd_map = open(argv[1], O_RDONLY);
	if (parse->fd_map == -1)
	{
		printf("Error fd\n");
		exit(-1);
	}
	return (parse);
}
