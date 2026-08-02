/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprudnik <dprudnik@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:28:03 by dprudnik          #+#    #+#             */
/*   Updated: 2026/07/15 16:56:20 by dprudnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	handle_close(t_game *game)
{
	exit_game(game, NULL);
	return (0);
}

int	handle_key_press(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		exit_game(game, NULL);
	else if (keysym == XK_w)
		game->keys.key_w = 1;
	else if (keysym == XK_a)
		game->keys.key_a = 1;
	else if (keysym == XK_s)
		game->keys.key_s = 1;
	else if (keysym == XK_d)
		game->keys.key_d = 1;
	else if (keysym == XK_Left)
		game->keys.key_left = 1;
	else if (keysym == XK_Right)
		game->keys.key_right = 1;
	return (0);
}

int	handle_key_release(int keysym, t_game * game)
{
	if (keysym == XK_w)
		game->keys.key_w = 0;
	else if (keysym == XK_a)
		game->keys.key_a = 0;
	else if (keysym == XK_s)
		game->keys.key_s = 0;
	else if (keysym == XK_d)
		game->keys.key_d = 0;
	else if (keysym == XK_Left)
		game->keys.key_left = 0;
	else if (keysym == XK_Right)
		game->keys.key_right = 0;
	return (0);
}
