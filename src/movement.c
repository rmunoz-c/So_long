/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 16:06:10 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-14 16:06:10 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_status(t_game *game, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	else if (dir == DOWN)
		y += 1;
	else if (dir == RIGHT)
		x += 1;
	else if (dir == LEFT)
		x -= 1;
	if (game->map.map[y][x] == 'C')
	{
		game->map.map[y][x] = '0';
		game->c--;
	}
	if (game->map.map[y][x] == 'E' && game->c == 0)
		return (win_game(game));
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (y > 0 && game->map.map[y - 1][x] != '1')
	{
		move_status(game, x, y, UP);
		if (game->map.map[y - 1][x] == 'E' && (game->c != 0 || game->e == 1))
			return ;
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, 
								x * IMG_W, y * IMG_H);
		game->map.map[y][x] = '0';
		y--;
		print_moves(game);
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, 
								x * IMG_W, y * IMG_H);
		mlx_put_image_to_window(game->mlx, game->win, game->player_img_right, 
								x * IMG_W, y * IMG_H);
		game->map.map[y][x] = 'P';
		game->player_y = y;
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (y < game->map.height && game->map.map[y + 1][x] != '1')
	{
		move_status(game, x, y, DOWN);
		if (game->map.map[y + 1][x] == 'E' && (game->c != 0 || game->e == 1))
			return ;
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, 
								x * IMG_W, y * IMG_H);
		game->map.map[y][x] = '0';
		y++;
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, 
								x * IMG_W, y * IMG_H);
		mlx_put_image_to_window(game->mlx, game->win, game->player_img_left, 
								x * IMG_W, y * IMG_H);
		game->map.map[y][x] = 'P';
		game->player_y = y;
		print_moves(game);
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (x < game->map.width && game->map.map[y][x + 1] != '1')
	{
		move_status(game, x, y, RIGHT);
		if (game->map.map[y][x + 1] == 'E' && (game->c != 0 || game->e == 1))
			return ;
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, 
								x * IMG_W, y * IMG_H);
		game->map.map[y][x] = '0';
		x++;
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, 
								x * IMG_W, y * IMG_H);
		mlx_put_image_to_window(game->mlx, game->win, game->player_img_right, 
								x * IMG_W, y * IMG_H);
		game->map.map[y][x] = 'P';
		game->player_x = x;
		print_moves(game);
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (x > 0 && game->map.map[y][x - 1] != '1')
	{
		move_status(game, x, y, LEFT);
		if (game->map.map[y][x - 1] == 'E' && (game->c != 0 || game->e == 1))
			return ;
		game->moves++;
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, 
								x * IMG_W, y * IMG_H);
		game->map.map[y][x] = '0';
		x--;
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, 
								x * IMG_W, y * IMG_H);
		mlx_put_image_to_window(game->mlx, game->win, game->player_img_left, 
								x * IMG_W, y * IMG_H);
		game->map.map[y][x] = 'P';
		game->player_x = x;
		print_moves(game);
	}
}