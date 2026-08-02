/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:27:56 by opaulman          #+#    #+#             */
/*   Updated: 2026/07/17 17:08:48 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	file_check(t_game *game, char **argv)
{
	int	fd;

	game->map.cubfile = ft_strjoin("assets/", argv[1]);
	fd = open(game->map.cubfile, O_RDONLY);
	if (fd < 0)
	{
		return (-1);
	}
	close(fd);
	return (0);
}


int	check_input(t_game *game, char **argv)
{
	if (file_check(game, argv) != 0)
	{
		printf("wrong file: %s!!\n", game->map.cubfile);
		exit(1);
	}
	if (color_check(game) != 0)
	{
		printf("wrong color structure\n");
		exit(1);
	}
	return (0);
}
