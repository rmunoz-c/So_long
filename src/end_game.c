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
	ft_free_game(game->map.map, game->map.height);
	exit(EXIT_SUCCESS);
	return(0);
}

void	win_game(t_game *game)
{
	game->e = 1;
	game->moves++;
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, game->map.width / 2 * IMG_W, 
					game->map.height / 2 * IMG_H, 0x9EFF9E, "VICTORY IS YOURS");
	write (1, "\n", 1);
	write (1, "\x1B[32m", 5);
	write (1, "¡¡VICTORY IS YOURS!!", 21);
	write(1, "\x1b[0m", 5);
}