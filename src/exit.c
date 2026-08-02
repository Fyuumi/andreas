/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <dprudnik@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:18:00 by denis             #+#    #+#             */
/*   Updated: 2026/07/15 15:25:36 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	free(game->map.path_no_texture);
	free(game->map.path_so_texture);
	free(game->map.path_we_texture);
	free(game->map.path_ea_texture);
}

void	cleanup(t_game *game)
{
	//[]free resources like map etc...
	free_map(game);
	if (game->map.cubfile)
		free(game->map.cubfile);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	exit_game(t_game *game, const char *msg)
{
	if (msg)
		perror(msg);
	cleanup(game);
	if (msg)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
