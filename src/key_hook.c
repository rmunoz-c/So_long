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

#include "../include/so_long.h"

void	player_pos(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	while (game->player_y < game->map.height)
	{
		while (game->player_x < game->map.width)
		{
			if (game->map.map[game->player_y][game->player_x] == 'P')
				return ;
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
	if (keycode == XK_Escape)
		return (close_game(game));
	else if (game->e == 1)
		return (0);
	else if (keycode == XK_w)
		move_up(game);
	else if (keycode == XK_s)
		move_down(game);
	else if (keycode == XK_a)
		move_left(game);
	else if (keycode == XK_d)
		move_right(game);
	return (0);		
}