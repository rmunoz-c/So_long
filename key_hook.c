/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 16:29:51 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-08 16:29:51 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	while (game->player_y < game->map.height)
	{
		while (game->player_x < game->map.width)
		{
			if (game->map.map[game->player_y][game->player_x] == 'P')
				break ;
			game->player_x++;
		}
		if (game->map.map[game->player_y][game->player_x] == 'P')
			break ;
		game->player_x = 0;
		game->player_y++;
	}
}

int	update_player(int keycode, t_game *game)
{
	player_pos(game);
	if (keycode == ESC)
		return (0);
	else if (game->e == 1)
		return (0);
	else if(keycode == UP)
		move_up(game);
	else if(keycode == DOWN)
		move_down(game);
	else if(keycode == LEFT)
		move_left(game);
	else if(keycode == RIGHT)
		move_right(game);
	return (0);		
}