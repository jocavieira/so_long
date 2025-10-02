/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:59:04 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/10/02 08:16:36 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
    if (keycode == W)
        move_player(game, 0, -1);
    else if (keycode == S)
        move_player(game, 0, 1);
    else if (keycode == A)
        move_player(game, -1, 0);
    else if (keycode == D)
        move_player(game, 1, 0);
    else if (keycode == ESC)
        exit_game("Too hard for you?", game);
    return (0);
}

void move_player(t_game *game, int dx, int dy)
{
    int nx = game->map.player_x + dx;
    int ny = game->map.player_y + dy;
    char dest = game->map.grid[ny][nx];

    if (dest == '1' || (dest == 'E' && game->map.collected != game->map.collect_count))
        return;
    if (dest == 'C')
        game->map.collected++;
    game->map.grid[game->map.player_y][game->map.player_x] = '0';
    game->map.player_x = nx;
    game->map.player_y = ny;
    game->map.grid[ny][nx] = 'P';
    draw_map(game);
    count_move(game);
    if (dest == 'E')
        exit_game("You won! CONGRATULATIONS!!", game);
}

void    count_move(t_game *game)
{
    game->map.moves++;
    ft_printf("Movements: %d\n", game->map.moves);
}

