/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:45:54 by opaulman          #+#    #+#             */
/*   Updated: 2026/07/17 17:05:02 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_null(t_game *game)
{
	game->map.map = NULL;
	game->map.path_ea_texture = NULL;
	game->map.path_no_texture = NULL;
	game->map.path_so_texture = NULL;
	game->map.path_we_texture = NULL;
	return ;
}