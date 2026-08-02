/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:23:10 by opaulman          #+#    #+#             */
/*   Updated: 2026/07/17 17:24:22 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_infos_map(t_game *game)
{
	int		fd;
	char	*line;

	game->map.height = 0;
	game->map.width = 0;
	fd = open(game->map.cubfile, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if ((line[0] == 32 || line[0] == '1'))
		{
			if ((int)ft_strlen(line) > game->map.width)
				game->map.width = ft_strlen(line);
			game->map.height++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return ;
}
static int	rgb_to_int(char *rgb)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = (ft_strlen(rgb) - 1);
	while (rgb[i] != ',')
		i--;
	b = ft_atoi(rgb + i + 1);
	rgb[i--] = '\0';
	while (rgb[i] != ',')
		i--;
	g = ft_atoi(rgb + i + 1);
	rgb[i--] = '\0';
	r = ft_atoi(rgb);
	return ((r << 16) | (g << 8) | b);
}

void	nswe_infos(t_game *game)
{
	int fd;
	char *line;

	fd = open(game->map.cubfile, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'N' && line[1] == 'O')
			game->map.path_no_texture = ft_strdup(line + 3);
		if (line[0] == 'S' && line[1] == 'O')
			game->map.path_so_texture = ft_strdup(line + 3);
		if (line[0] == 'W' && line[1] == 'E')
			game->map.path_we_texture = ft_strdup(line + 3);
		if (line[0] == 'E' && line[1] == 'A')
			game->map.path_ea_texture = ft_strdup(line + 3);
		if (line[0] == 'F')
			game->map.floor_color = rgb_to_int(line + 2);
		if (line[0] == 'C')
			game->map.ceiling_color = rgb_to_int(line + 2);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return ;
}