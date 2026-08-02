/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:27:37 by dprudnik          #+#    #+#             */
/*   Updated: 2026/07/20 16:07:37 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	draw_map(t_game *game, int start_x, int start_y, int size)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == ' ')
				x++;
			else if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'N'
					|| game->map.map[y][x] == 'W' || game->map.map[y][x] == 'S'
					|| game->map.map[y][x] == 'E')
				draw_square(game, start_x + (x * size), start_y + (y * size)
					, size, game->map.floor_color);
			else if (game->map.map[y][x] == '1')
				draw_square(game, start_x + (x * size), start_y + (y * size)
					, size, game->map.ceiling_color);
			x++;
		}
		y++;
	}
}

void	draw_position(t_game *g, int tile_size)
{
	double	start_x;
	double	start_y;
	double	width;
	double	i;
	double	j;

	i = -(tile_size / 2);
	width = tile_size / 2;
	while (i < tile_size)
	{
		start_x = (int)(g->state.pos.x * tile_size + (g->state.dir.x * i));
		start_y = (int)(g->state.pos.y * tile_size + (g->state.dir.y * i));
		j = -width;
		while (j <= width)
		{
			ft_pixel_put(g, start_x + g->state.plane.x * j,
				start_y + g->state.plane.y * j, 0x00FF0000);
			j++;
		}
		width -= 0.5F;
		i++;
	}
}
