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
	map->background_img= mlx_xpm_file_to_image(map->mlx,
								"textures/Background.xpm", &x, &y);
	map->wall_img = mlx_xpm_file_to_image(map->mlx, 
								"textures/Wall.xpm", &x, &y);
	map->collectible_img = mlx_xpm_file_to_image(map->mlx, 
								"textures/Broam.xpm", &x, &y);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, 
								"textures/Exit.xpm", &x, &y);
	set_player_image(map);
}

void	set_player_image(t_game *player)
{
	int x;
	int y;

	x = IMG_W;
	y = IMG_H;
	player->player_img_down = mlx_xpm_file_to_image(player->mlx,
								"textures/Dalinar_left.xpm", &x, &y);
	player->player_img_left = mlx_xpm_file_to_image(player->mlx,
								"textures/Dalinar_left.xpm", &x, &y);
	player->player_img_up = mlx_xpm_file_to_image(player->mlx,
								"textures/Dalinar_right.xpm", &x, &y);
	player->player_img_right = mlx_xpm_file_to_image(player->mlx,
								"textures/Dalinar_right.xpm", &x, &y);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, 
								x * IMG_W, y * IMG_H);
	else if (tile == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player_img_right,
								x * IMG_W, y * IMG_H);
		game->player_x = x;
		game->player_y = y;
	}
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, 
		 						x * IMG_W, y * IMG_H);
	else if (tile == 'E')
		 mlx_put_image_to_window(game->mlx, game->win, game->exit_img, 
		 						x * IMG_W, y * IMG_H);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->background_img,
								 x * IMG_W, y * IMG_H);
}

void	render_map(t_game *game)
{
	int	y;
	int x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, game->map.map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	write (1, moves, ft_strlen(moves));
	write (1, " movements\n", 11);
	free(moves);
}
