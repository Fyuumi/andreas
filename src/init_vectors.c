/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:10:34 by dprudnik          #+#    #+#             */
/*   Updated: 2026/07/20 15:31:52 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	set_north(t_game *game)
{
	game->state.dir.x = 0;
	game->state.dir.y = -1;
	game->state.plane.x = 0.66;
	game->state.plane.y = 0;
}

static void	set_east(t_game *game)
{
	game->state.dir.x = 1;
	game->state.dir.y = 0;
	game->state.plane.x = 0;
	game->state.plane.y = 0.66;
}

static void	set_south(t_game *game)
{
	game->state.dir.x = 0;
	game->state.dir.y = 1;
	game->state.plane.x = -0.66;
	game->state.plane.y = 0;

}

static void	set_west(t_game *game)
{
	game->state.dir.x = -1;
	game->state.dir.y = 0;
	game->state.plane.x = 0;
	game->state.plane.y = -0.66;
}

void	init_vectors(char c, t_game *game)
{
	if (c == 'N')
		set_north(game);
	else if (c == 'E')
		set_east(game);
	else if (c == 'S')
		set_south(game);
	else if (c == 'W')
		set_west(game);
	return ;
}
