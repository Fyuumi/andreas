/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:05:36 by opaulman          #+#    #+#             */
/*   Updated: 2026/07/17 17:06:30 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	non_valid_number(char *line, int start)
{
	int	i;

	i = start;
	i--;
	while (line[i] == 32)
		i--;
	if (line[i] < 48 || line[i] > 57)
		return (1);
	i = start;
	i++;
	while (line[i] == 32)
		i++;
	if (line[i] < 48 || line[i] > 57)
		return (1);
	return (0);
}
static int	com_count_check(char *line)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			if (non_valid_number(line, i))
				return (1);
			num++;
		}
		i++;
	}
	if (num != 2)
		return (1);
	return (0);
}
static int	color_line_check(char *line)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = (ft_strlen(line) - 1);
	while (line[i] != ',')
		i--;
	b = ft_atoi(line + i + 1);
	line[i--] = '\0';
	while (line[i] != ',')
		i--;
	g = ft_atoi(line + i + 1);
	line[i--] = '\0';
	r = ft_atoi(line);
	if (r > 255 || g > 255 || b > 255)
		return (1);
	return (0);
}
int	color_check(t_game *game)
{
	int fd;
	char *line;

	fd = open(game->map.cubfile, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'F' || line[0] == 'C')
		{
			if (com_count_check(line))
			{
				return (-1);
			}
			if (color_line_check(line))
				return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}