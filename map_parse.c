/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 14:11:32 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-10 14:11:32 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int	len;
	int	i;

	len = ft_strlen(map[0]);
	i = 1;

	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

void	check_walls(t_game *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map.map[0][x] != '\0' && map->map.map[0][x] == '1')
		x++;
	if (map->map.map[0][x] != '\0')
		ft_error("Error\n", TRUE);
	y = 1;
	while (y < map->map.height)
	{
		if (map->map.map[y][0] != '1' || 
			map->map.map[y][map->map.width - 1] != '1')
			ft_error("Error\n", TRUE);
		y++;
	}
	x = 0;
	while (map->map.map[map->map.height - 1][x] != '1')
		x++;
	if (map->map.map[map->map.height - 1][x] != '1')
			ft_error("Error\n", TRUE);
}

int check_components(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map.height)
	{
		while (x < map->map.width)
		{
			if (map->map.map[x][y] == 'P')
				map->p += 1;
			else if (map->map.map[x][y] == 'E')
				map->e += 1;
			else if (map->map.map[x][y] == 'C')
				map->c += 1;
			else if (map->map.map[x][y] == '0' || map->map.map[x][y] == '1')
				;
			else
				ft_error("Error\n", TRUE);
			x++;
		}
		x = 0;
		y++;
	}
	if (map->p != 1 || map->e < 1 || map->c < 1)
		ft_error("Error\n", TRUE);
}


