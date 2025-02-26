/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 15:52:37 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-16 15:52:37 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_initializer(t_game *game, char **argv)
{
	game->filename = argv[1];
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(game));
	if (argc == 2)
	{
		game_initializer(&game, argv);
		map_parse(&game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.map.width * IMG_W,
				game.map.height * IMG_H, WINDOW_NAME);
		set_map_image(&game);
		mlx_hook(game.win, KeyPress, KeyPressMask, update_player, &game);
		mlx_hook(game.win, 17, 0, close_game, &game);
		render_map(&game);
		mlx_loop(game.mlx);
	}
	ft_error("Error\n Try with ./so_long 'map_file.ber'\n", TRUE);
	return (EXIT_FAILURE);
}
