/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 17:28:54 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-14 17:28:54 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_traveler(t_game *game, int x, int y)
{
	char	comp;

	comp = game->map.copy[y][x];
	if (comp == '0' || comp == 'P')
		game->map.copy[y][x] = '1';
	else if (comp == 'C')
	{
		game->check_c -= 1;
		game->map.copy[y][x] = '1';
	}
	else if (comp == 'E')
	{
		game->check_e -= 1;
		game->map.copy[y][x] = '1';
	}
	else
		return ;
	path_traveler (x + 1, y, game);
	path_traveler (x - 1, y, game);
	path_traveler (x, y + 1, game);
	path_traveler (x, y - 1, game);
}

void	path_finder(t_game *game)
{
	game->check_c = game->c;
	game->check_e = game->e;
	player_pos(game);
	path_traveler(game->player_x, game->player_y, game);
	if (game->check_c != 0 || game->check_e >= game->e)
	{
		ft_free_array(game->map.map);
		ft_free_array(game->map.copy);
		ft_error("Error: No valid path found!\n", TRUE);
	}
}
