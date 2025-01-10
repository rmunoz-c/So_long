/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 15:27:45 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-08 15:27:45 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_image(t_game *map)
{
	int	x;
	int y;

	x = IMG_W;
	y = IMG_H;
	map->img_background.img = mlx_xpm_file_to_image(map->window.mlx,
								"textures/Background.xpm", &x, &y);
	map->img_wall.img = mlx_xpm_file_to_image(map->window.mlx, 
								"textures/Wall.xpm", &x, &y);
	map->img_collectible.img = mlx_xpm_file_to_image(map->window.mlx, 
								"textures/Broam.xpm", &x, &y);
	map->img_exit.img = mlx_xpm_file_to_image(map->window.mlx, 
								"textures/Exit.xpm", &x, &y);
	set_player_image(map);
}

void	set_player_image(t_game *player)
{
	int x;
	int y;

	x = IMG_W;
	y = IMG_H;
	player->img_player_down.img = mlx_xpm_file_to_image(player->window.mlx,
								"textures/Dalinar_left.xpm", &x, &y);
	player->img_player_left.img = mlx_xpm_file_to_image(player->window.mlx,
								"textures/Dalinar_left.xpm", &x, &y);
	player->img_player_up.img = mlx_xpm_file_to_image(player->window.mlx,
								"textures/Dalinar_right.xpm", &x, &y);
	player->img_player_right.img = mlx_xpm_file_to_image(player->window.mlx,
								"textures/Dalinar_right.xpm", &x, &y);
}
