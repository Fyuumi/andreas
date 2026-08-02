/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 16:29:02 by denis             #+#    #+#             */
/*   Updated: 2026/07/20 18:02:36 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dispay(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, "MLX pointer init failed!");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!game->win)
		exit_game(game, "Window creation failed!");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		exit_game(game, "Image creation failed!");
	game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->line_len,
			&game->endian);
}

static void	set_keys(t_game *game)
{
	game->keys.key_w = 0;
	game->keys.key_a = 0;
	game->keys.key_s = 0;
	game->keys.key_d = 0;
	game->keys.key_left = 0;
	game->keys.key_right = 0;

}

static void	set_spawn_position(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map.map[y])
	{
		x = 0;
		while (g->map.map[y][x])
		{
			if (g->map.map[y][x] == 'N' || g->map.map[y][x] == 'W'
				|| g->map.map[y][x] == 'S' || g->map.map[y][x] == 'E')
			{
				init_vectors(g->map.map[y][x], g);
				g->state.pos.x = x + 0.5;
				g->state.pos.y = y + 0.5;
				printf("\n--Spawn position_x%f--\n", g->state.pos.x);
				printf("--Spawn position_y%f--\n", g->state.pos.y);
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	init_state(t_game *game)
{
	game->state.last_time = 0;
	game->state.mv_speed = MOVEMENT_SPEED;
	game->state.rot_speed = ROTATION_SPEED;
	set_spawn_position(game);
}

void	init_game(t_game *game)
{
	init_dispay(game);
	init_map(game);
	set_keys(game);
	init_state(game);
}
