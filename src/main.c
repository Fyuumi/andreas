/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:18:25 by denis             #+#    #+#             */
/*   Updated: 2026/07/20 16:27:25 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_time(t_game *g)
{
	struct timeval	tv;
	long			now;

	gettimeofday(&tv, NULL);
	now = tv.tv_sec * 1000000L + tv.tv_usec;
	if (g->state.last_time == 0)
		g->state.delta_time = 0.0;
	else
		g->state.delta_time = (now - g->state.last_time) / 1000000.0;
	g->state.last_time = now;
}

int	game_loop(t_game *g)
{
	update_time(g);
	move_point(g);  //[]movement 
	clear_image(g); //[]clear image 
	cast_rays(g, &g->state); //[]cast_rays
	draw_map(g, 0, 0, MINIMAP_BLOCK_SIZE); //[]ui_overlay
	draw_position(g, MINIMAP_BLOCK_SIZE);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (printf("No Map provided!"), 1);
	set_null(&game);
	check_input(&game, argv);
	init_game(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, handle_key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, handle_key_release, &game);
	mlx_hook(game.win, DestroyNotify, NoEventMask, handle_close, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
