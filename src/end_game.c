/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 15:46:49 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-14 15:46:49 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h" 

int	ft_free_game(char **game, int i)
{
	while (i > 0)
		free(game[--i]);
	free(game);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->background_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->player_img_down);
	mlx_destroy_image(game->mlx, game->player_img_left);
	mlx_destroy_image(game->mlx, game->player_img_right);
	mlx_destroy_image(game->mlx, game->player_img_up);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_game(game->map.map, game->map.height);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_and_exit(t_game *game, char *error_message)
{
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_free_game(game->map.map, game->map.height);
	ft_free_game(game->map.copy, game->map.height);
	if (error_message)
		ft_error(error_message, TRUE);
	exit(EXIT_FAILURE);
}

void	win_game(t_game *game)
{
	game->check_e = 1;
	game->moves++;
	print_moves(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, game->map.width / 2 * IMG_W,
		game->map.height / 2 * IMG_H, 0x9EFF9E, "VICTORY IS YOURS");
	write (1, "\n", 1);
	write (1, "\x1B[32m", 5);
	write (1, "¡¡VICTORY IS YOURS!!\n", 23);
	write(1, "\x1b[0m", 5);
}
