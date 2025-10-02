/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:06:35 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/09/28 13:50:30 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    draw_tile(t_game *game, char c, int x, int y)
{
    void    *img;
	mlx_put_image_to_window(game->mlx, game->win,
                            game->floor.ptr, x * TILE_SIZE, y * TILE_SIZE);
                            
    img = NULL;

    if (c == '1')
        img = game->wall.ptr;
    else if (c == '0')
        img = game->floor.ptr;
    else if (c == 'P')
        img = game->player.ptr;
    else if (c == 'E')
	{
		if (game->map.collected == game->map.collect_count)
			img = game->exit_o.ptr;
		else
			img = game->exit_c.ptr;
	}
    else if (c == 'C')
        img = game->collectible.ptr;
    if (img)
        mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

void    draw_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            draw_tile(game, game->map.grid[y][x], x, y);
            x++;
        }
        y++;
    }
}