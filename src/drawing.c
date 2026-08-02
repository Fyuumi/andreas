/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:47:51 by dprudnik          #+#    #+#             */
/*   Updated: 2026/07/20 16:07:41 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	clear_image(t_game *game)
{
	int	total;
	int	i;
	int	*pix;

	i = 0;
	total = HEIGHT * WIDTH;
	pix = (int *)game->addr;
	while (i < total)
	{
		pix[i] = 0x00000000;
		i++;
	}
}

void	ft_pixel_put(t_game *game, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || y < 0
		|| x >= WIDTH
		|| y >= HEIGHT)
		return ;
	i = game->bpp - 8;
	pixel = game->addr + (y * game->line_len + x * (game->bpp / 8));
	while (i >= 0)
	{
		if (game->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (game->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	draw_square(t_game *game, int x, int y, int size, int color)
{
	int dx;
	int dy;

	dx = x;
	while (dx < (size + x))
	{
		dy = y;
		while (dy < (size + y))
		{
			ft_pixel_put(game, dx, dy, color);
			dy++;
		}
		dx++;
	}
}

// NOTE : drawing with pixels from texture map. Might move to texures.c
// Will be called by draw_line() in raycasting.c
// void	draw_textures(t_game *g, t_ray *r, ... )
