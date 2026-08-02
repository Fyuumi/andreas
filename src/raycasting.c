/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:34:45 by dprudnik          #+#    #+#             */
/*   Updated: 2026/07/22 14:19:03 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	calculate_delta(t_ray *r)
{
	if (r->ray_dir_x == 0)
		r->delta_x = 1e30;
	else
		r->delta_x = fabs(1.0 / r->ray_dir_x);

	if (r->ray_dir_y == 0)
		r->delta_y = 1e30;
	else
		r->delta_y = fabs(1.0 / r->ray_dir_y);
}

static void	calculate_step(t_state *s, t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->stepx = -1;
		r->side_dist_x = (s->pos.x - r->mapx) * r->delta_x;
	}
	else
	{
		r->stepx = 1;
		r->side_dist_x = (r->mapx + 1.0 - s->pos.x) * r->delta_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->stepy = -1;
		r->side_dist_y = (s->pos.y - r->mapy) * r->delta_y;
	}
	else
	{
		r->stepy = 1;
		r->side_dist_y = (r->mapy + 1.0 - s->pos.y) * r->delta_y;
	}
}

static void	check_hit(t_ray *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_x;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_y;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (r->map_ptr[r->mapy][r->mapx] == '1')
			hit = 1;
	}
}

static void	draw_line(t_game *g, t_ray *r, int x)
{
	int	y;
	int line_height;
	int draw_start;
	int draw_end;

	line_height = (int)(HEIGHT / r->per_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if(draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if(draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	y = 0;
	while (y <= draw_start)
		ft_pixel_put(g, x, y++, g->map.ceiling_color);
	while (y <= draw_end)
		ft_pixel_put(g, x, y++, 0x9b7272 >> hit_direction(r));
	//^^^ temporary
	while (y < HEIGHT)
		ft_pixel_put(g, x, y++, g->map.floor_color);
}

void	cast_rays(t_game *g, t_state *s)
{
	int	x;
	t_ray	r;

	x = 0;
	r.map_ptr = g->map.map;
	while (x < WIDTH)
	{
		r.camera_x = 2.0 * x / (double)WIDTH - 1.0;
		r.ray_dir_x = s->dir.x + s->plane.x * r.camera_x;
		r.ray_dir_y = s->dir.y + s->plane.y * r.camera_x;
		r.mapx = (int)s->pos.x;
		r.mapy = (int)s->pos.y;
		calculate_delta(&r);
		calculate_step(s, &r);
		check_hit(&r);
		if(r.side == 0)
			r.per_wall_dist = (r.side_dist_x - r.delta_x);
		else
			r.per_wall_dist = (r.side_dist_y - r.delta_y);
		draw_line(g, &r, x);
		x++;
	}
}
