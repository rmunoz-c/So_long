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
		free (game->map.map);
	if (game->map.copy)
		free (game->map.copy);
	if (game->file)
		free (game->file);
	if (game->line)
		free (game->line);
	exit(EXIT_FAILURE);
}

void	read_map(t_game *game)
{
	int		fd;

	game->map.height = 0;
	game->line = "";
	game->file = NULL;
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error: Failed opening the file\n", TRUE);
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
	close(fd);
	game->map.map = ft_split(game->file, '\n');
	game->map.copy = ft_split(game->file, '\n');
	if (!game->map.map || !game->map.copy)
		ft_exit_free(game);
	free(game->file);
}

