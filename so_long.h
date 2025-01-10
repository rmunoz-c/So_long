/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 16:11:39 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-01-07 16:11:39 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "../mlx so_long/mlx/mlx.h"
# include "GetNextLine/get_next_line.h"


# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define ESC 53
# define IMG_W 32
# define IMG_H 32
# define WINDOW_NAME "so_long"

typedef struct s_player
{
	int	x;
	int	y;
	int	move_count;
}	t_player;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_collectible
{
	int	x;
	int	y;
	int	collected;
}	t_collectible;

typedef struct s_window
{
	int		width;
	int		height;
	void	*mlx;
	void	*win_ptr;
}	t_window;

typedef struct s_image
{
	int		width;
	int		height;
	void	*img;
}	t_image;

typedef struct s_game
{
	t_player		player;
	t_map			map;
	t_collectible	*collectibles;
	int				c;
	int				p;
	int				e;
	t_window		window;
	t_image			img_player_up;
	t_image			img_player_down;
	t_image			img_player_left;
	t_image			img_player_right;
	t_image			img_background;
	t_image			img_wall;
	t_image			img_collectible;
	t_image			img_exit;
}	t_game;


#endif