/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 14:14:02 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-10 14:14:02 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit_free(t_game *game)
{
	if (game->map.map)
		ft_free_game(game->map.map, game->map.height);
	if (game->map.copy)
		ft_free_game(game->map.copy, game->map.height);
	if (game->file)
		free(game->file);
	if (game->line)
		free(game->line);
	exit(EXIT_FAILURE);
}

void	close_map(t_game *game, int fd)
{
	close(fd);
	game->map.map = ft_split(game->file, '\n');
	game->map.copy = ft_split(game->file, '\n');
	if (!game->map.map || !game->map.copy)
		ft_exit_free(game);
	free(game->file);
}

void	read_map(t_game *game)
{
	int		fd;

	game->map.height = 0;
	game->line = "";
	game->file = NULL;
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error\n Failed opening the file\n", TRUE);
	while (game->line)
	{
		game->line = get_next_line(fd);
		if (game->line == NULL)
			break ;
		game->file = ft_strjoinfree(game->file, game->line);
		free(game->line);
		if (!game->file)
			ft_exit_free(game);
		game->map.height++;
	}
	close_map(game, fd);
}
