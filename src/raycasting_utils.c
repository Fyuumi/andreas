/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:33:41 by dprudnik          #+#    #+#             */
/*   Updated: 2026/07/22 14:18:02 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_hit_dir	hit_direction(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			return (WE_wall);
		return (EA_wall);
	}
	if (r->ray_dir_y > 0)
		return (NO_wall);
	return (SO_wall);
}

double	wall_hit_x(t_game *g, t_ray *r)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = g->state.pos.y + r->per_wall_dist * r->ray_dir_y;
	else
		wall_x = g->state.pos.x + r->per_wall_dist * r->ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	return (wall_x);
}
