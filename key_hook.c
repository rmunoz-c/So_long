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

int update_player(int keycode, t_game *game)
{
	if (keycode == UP)
	{
		game->player.y -= 1;
		mlx_put_image_to_window(game->window.mlx, game->window.win_ptr,
		game->img_player_up.img, game->player.x * IMG_W, game->player.y * IMG_H);
	}
}