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

void test_parse(t_game *game)
{
    printf("Test 1: Mapa válido\n");
    game->filename = "src/maps/map1.ber";
    read_map(game);
    check_file(game);
    is_rectangular(game);
    check_walls(game);
    check_components(game);
    printf("Mapa válido completado.\n");
    ft_free_game(game->map.map, game->map.height);  

    printf("\nTest 2: Mapa con paredes faltantes\n");
    game->filename = "src/maps/map_missing_top_wall.ber";
    read_map(game);
    check_file(game);
    is_rectangular(game);
    check_walls(game);
    check_components(game);
    printf("Este mensaje no debería aparecer si check_walls falla.\n");
    ft_free_game(game->map.map, game->map.height);
}

int main()
{
    t_game game;

    test_parse(&game);
    return 0;
}