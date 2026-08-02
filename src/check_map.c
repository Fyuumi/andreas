/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:36:22 by opaulman          #+#    #+#             */
/*   Updated: 2026/07/17 14:09:06 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	letter(char c)
{
	if (c == 32)
		return (1);
	else if (c == '1' || c == '0')
		return (1);
	else if (c == '\n' || c == '\0')
		return (1);
	else if (c == 'N' || c == 'S')
		return (2);
	else if (c == 'W' || c == 'E')
		return (2);
	else
	{
		printf("char: %c\n", c);
		return (0);
	}
}
static int	right_letter_check(t_game *game)
{
	int	x;
	int	y;
	int	flag;
	int	player_flag;

	flag = 0;
	player_flag = 0; // numbers of player
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x] && game->map.map[y][x] != '\n')
		{
			flag = letter(game->map.map[y][x]);
			if (flag == 0)
				return (printf("position: %d %d\n", y, x));
			if (flag == 2)
				player_flag++;
			if (player_flag == 2)
				exit_game(game, "map error/to many player");
			x++;
		}
		y++;
	}
	return (0);
}
static int	check_c(char c)
{
	if (c == '0' || c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}
static int	outer_wall_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		if (check_c(game->map.map[y][0]))
			return (-1);
		if (check_c(game->map.map[y][(ft_strlen(game->map.map[y]) - 2)]))
			return (-1);
		y++;
	}
	while (game->map.map[0][x] != '\n')
	{
		if (check_c(game->map.map[0][x++]))
			return (-1);
	}
	x = 0;
	while (game->map.map[game->map.height - 1][x] != '\0')
	{
		if (check_c(game->map.map[game->map.height - 1][x++]))
			return (-1);
	}
	return (0);
}
static int	zero_check_util(t_game *game, int y, int x)
{
	if (game->map.map[y + 1][x] == 32)
		return (-1);
	if (game->map.map[y - 1][x] == 32)
		return (-1);
	if (game->map.map[y][x + 1] == 32)
		return (-1);
	if (game->map.map[y][x - 1] == 32)
		return (-1);
	return (0);
}
static int	zero_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'N'
				|| game->map.map[y][x] == 'W' || game->map.map[y][x] == 'S'
				|| game->map.map[y][x] == 'E')
			{
				if (zero_check_util(game, y, x) < 0)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
int	map_check(t_game *game) // in init because needs generate map to check
{
	if (right_letter_check(game) != 0)
		exit_game(game, "map error/wrong letter");
	if (outer_wall_check(game) != 0)
		exit_game(game, "map error/walls needed in the outer corner");
	if (zero_check(game) != 0)
		exit_game(game, "map error/zero on space");
	return (0);
}
