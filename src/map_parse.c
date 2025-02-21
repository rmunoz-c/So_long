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

#include "../include/so_long.h"

void	is_rectangular(t_game *game)
{
	int		len;
	int		x;
	int		y;

	x = 0;
	y = 0;
	len = ft_strlen(game->map.map[y]);
	while (y < game->map.height)
	{
		x = ft_strlen(game->map.map[y]);
		if (len != x)
			ft_error("Error: Map is not rectangular!", TRUE);
		y++;
	}
	game->map.width = len;
}

void	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.map[0][x] != '\0' && game->map.map[0][x] == '1')
		x++;
	if (game->map.map[0][x] != '\0')
		ft_error("Error: Top wall missing!\n", TRUE);
	y = 1;
	while (y < game->map.height)
	{
		if (game->map.map[y][0] != '1' ||
			game->map.map[y][game->map.width - 1] != '1')
			ft_error("Error: Wall missing on side!\n", TRUE);
		y++;
	}
	x = 0;
	while (game->map.map[game->map.height - 1][x] != '\0')
	{
		if (game->map.map[game->map.height - 1][x] != '1')
			ft_error("Error: Bottom wall missing!\n", TRUE);
		x++;
	}
}

void	check_components(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'P')
				game->p += 1;
			else if (game->map.map[y][x] == 'E')
				game->e += 1;
			else if (game->map.map[y][x] == 'C')
				game->c += 1;
			else if (game->map.map[y][x] == '0' || game->map.map[y][x] == '1')
				;
			else
				ft_error("Error: Invalid character detected!\n", TRUE);
			x++;
		}
		y++;
	}
	if (game->p != 1 || game->e < 1 || game->c < 1)
		ft_error("Error: Missing components!\n", TRUE);
}

void	check_file(t_game *game)
{
	size_t	len;

	len = ft_strlen(game->filename);
	if (game->filename[len - 1] != 'r')
		ft_error("Error: Wrong file, not .BER extension!", TRUE);
	if (game->filename[len - 2] != 'e')
		ft_error("Error: Wrong file, not .BER extension!", TRUE);
	if (game->filename[len - 3] != 'b')
		ft_error("Error: Wrong file, not .BER extension!", TRUE);
	if (game->filename[len - 4] != '.')
		ft_error("Error: Wrong file, not .BER extension!", TRUE);
	if (!ft_strnstr(game->filename, ".ber", ft_strlen(game->filename)))
		ft_error("Error: Wrong file, not .BER extension!", TRUE);
}

void	map_parse(t_game *game)
{
	check_file(game);
	read_map(game);
	is_rectangular(game);
	check_walls(game);
	check_components(game);
	path_finder(game);
	ft_free_array(game->map.copy);
}
