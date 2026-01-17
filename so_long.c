/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:59:04 by jocarlo2          #+#    #+#             */
/*   Updated: 2026/01/14 08:40:31 by jocavieira       ###   ########.fr       */
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
	int	nx;
	int	ny;
	char	dest;

	nx = game->map.player_x + dx;
	ny = game->map.player_y + dy;
    if (nx < 0 || nx >= game->map.width || ny < 0 || ny >= game->map.height)
        return;
    dest = game->map.grid[ny][nx];
    if (dest == '1')
        return;
    if (dest == 'C')
        game->map.collected++;
    game->map.grid[game->map.player_y][game->map.player_x] = game->map.prev_tile;
    game->map.player_x = nx;
    game->map.player_y = ny;
    if (dest == 'E' && game->map.collected < game->map.collect_count)
        game->map.prev_tile = 'E'; 
    else
        game->map.prev_tile = '0';
    game->map.grid[ny][nx] = 'P';
    draw_map(game);
    count_move(game);
    if (dest == 'E' && game->map.collected == game->map.collect_count)
        exit_game("You won! CONGRATULATIONS!!", game);
}

void    count_move(t_game *game)
{
    game->map.moves++;
    ft_printf("Movements: %d\n", game->map.moves);
}

