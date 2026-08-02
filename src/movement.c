/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:18:39 by dprudnik          #+#    #+#             */
/*   Updated: 2026/07/20 18:03:03 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	try_move(t_game *g, double new_y, double new_x)
{
	if (g->map.map[(int)new_y][(int)new_x] == '1')
		return (0);
	return (1);
}

static void	move_vertical(t_game *g, double step)
{
	if (g->keys.key_w && try_move(g, g->state.pos.y + g->state.dir.y * step,
			g->state.pos.x + g->state.dir.x * step))
	{
		g->state.pos.y += g->state.dir.y * step;
		g->state.pos.x += g->state.dir.x * step;
	}
	if (g->keys.key_s && try_move(g, g->state.pos.y - g->state.dir.y * step,
			g->state.pos.x - g->state.dir.x * step))
	{
		g->state.pos.y -= g->state.dir.y * step;
		g->state.pos.x -= g->state.dir.x * step;
	}
}

static void	move_horizontal(t_game *g, double step)
{
	if (g->keys.key_a && try_move(g, g->state.pos.y + (-g->state.dir.x) * step,
			g->state.pos.x + (g->state.dir.y) * step))
	{
		g->state.pos.y += (-g->state.dir.x) * step;
		g->state.pos.x += (g->state.dir.y) * step;
	}
	if (g->keys.key_d && try_move(g, g->state.pos.y + (g->state.dir.x) * step,
			g->state.pos.x + (-g->state.dir.y) * step))
	{
		g->state.pos.y += (g->state.dir.x) * step;
		g->state.pos.x += (-g->state.dir.y) * step;
	}
}

static void	rotate_vector(t_vect *v, double angle)
{
	double	old_x;

	old_x = v->x;
	v->x = v->x * cos(angle) - v->y * sin(angle);
	v->y = old_x * sin(angle) + v->y * cos(angle);
}

static void	rotate_state(t_game *g, double rot)
{
	if (g->keys.key_left)
	{
		rotate_vector(&g->state.dir, -rot);
		rotate_vector(&g->state.plane, -rot);
	}
	if (g->keys.key_right)
	{
		rotate_vector(&g->state.dir, rot);
		rotate_vector(&g->state.plane, rot);
	}
}

void	move_point(t_game *g)
{
	double	step;
	double	angle;

	step = g->state.mv_speed * g->state.delta_time;
	angle = g->state.rot_speed * g->state.delta_time;
	move_vertical(g, step);
	move_horizontal(g, step);
	rotate_state(g, angle);
}
