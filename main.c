/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:04:09 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/10/02 07:51:46 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  game;

    if (argc != 2)
    {
        write(2, "Usage: ./so_long <map_file>\n", 28);
        return (1);
    }
    if (check_map(argv[1], &game.map))
        map_error_exit("Invalid map", &game.map);
    game.mlx = mlx_init();
    if (!game.mlx)
        exit_game("Error: mlx_init failed", &game);
    game.win = mlx_new_window(game.mlx,
            game.map.width * TILE_SIZE, game.map.height * TILE_SIZE, "so_long");
    if (!game.win)
        exit_game("Error: mlx_new_window failed", &game);
    if (load_images(&game))
        exit_game("Error: failed to load images", &game);
    draw_map(&game);
    mlx_key_hook(game.win, key_hook, &game);
    mlx_hook(game.win, 17, 0, (int (*)())close_window, &game); // fecha com X
    mlx_loop(game.mlx);
    return (0);
}



