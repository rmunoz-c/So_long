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

#include "../include/so_long.h"

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
		return ;
	}
	else
		return ;
	path_traveler (game, x + 1, y);
	path_traveler (game, x - 1, y);
	path_traveler (game, x, y + 1);
	path_traveler (game, x, y - 1);
}

void	path_finder(t_game *game)
{
	game->check_c = game->c;
	game->check_e = game->e;
	player_pos(game);
	path_traveler(game, game->player_x, game->player_y);
	if (game->check_c != 0 || game->check_e >= game->e)
	{
		ft_free_game(game->map.map, game->map.height);
		ft_free_game(game->map.copy, game->map.height);
		ft_error("Error\n No valid path found!\n", TRUE);
	}
}
