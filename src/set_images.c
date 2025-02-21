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

#include "../include/so_long.h"

void	set_map_image(t_game *map)
{
	int	x;
	int	y;

	x = IMG_W;
	y = IMG_H;
	map->background_img = mlx_xpm_file_to_image(map->mlx,
			"src/textures/Background.xpm", &x, &y);
	map->wall_img = mlx_xpm_file_to_image(map->mlx,
			"src/textures/Wall.xpm", &x, &y);
	map->collectible_img = mlx_xpm_file_to_image(map->mlx,
			"src/textures/Broam.xpm", &x, &y);
	map->exit_img = mlx_xpm_file_to_image(map->mlx,
			"src/textures/Exit.xpm", &x, &y);
	set_player_image(map);
}

void	set_player_image(t_game *player)
{
	int	x;
	int	y;

	x = IMG_W;
	y = IMG_H;
	player->player_img_down = mlx_xpm_file_to_image(player->mlx,
			"src/textures/Dalinar_left.xpm", &x, &y);
	player->player_img_left = mlx_xpm_file_to_image(player->mlx,
			"src/textures/Dalinar_left.xpm", &x, &y);
	player->player_img_up = mlx_xpm_file_to_image(player->mlx,
			"src/textures/Dalinar_right.xpm", &x, &y);
	player->player_img_right = mlx_xpm_file_to_image(player->mlx,
			"src/textures/Dalinar_right.xpm", &x, &y);
}

void	render_tile(t_game *game, int x, int y)
{
	int	tile;

	tile = game->map.map[y / IMG_H][x / IMG_W];
	if (tile == 'C' || tile == 'P' || tile == 'E' || tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->background_img,
			x, y);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img,
			x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img_right,
			x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
			x, y);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			x, y);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			render_tile(game, x * IMG_H, y * IMG_W);
			x++;
		}
		x = 0;
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
