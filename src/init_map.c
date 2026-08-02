/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:37:57 by opaulman          #+#    #+#             */
/*   Updated: 2026/07/17 17:32:23 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	generate_map(t_game *game)
{
	int		i;
	char	*line;
	int		fd;
	int		flag;

	flag = 0;
	i = 0;
	fd = open(game->map.cubfile, O_RDONLY);
	game->map.map = ft_calloc(sizeof(char *), (game->map.height + 2));
	line = get_next_line(fd);
	while (line && i <= game->map.height)
	{
		if (line[0] == '1' || line[0] == 32)
			flag = 1;
		if (flag == 1)
		{
			game->map.map[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	game->map.map[i] = NULL;
	close(fd);
	return ;
}

void	init_map(t_game *game)
{
	get_infos_map(game); // height and width recieved in the struct
	nswe_infos(game);
	generate_map(game);
	map_check(game);
	print2d(game->map.map);
	return ;
}