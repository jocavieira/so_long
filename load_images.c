/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:56:35 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/09/28 14:21:58 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    load_images(t_game *game)
{
    game->wall.ptr = mlx_xpm_file_to_image(game->mlx,
            "assets/wall.xpm", &game->wall.w, &game->wall.h);
    game->floor.ptr = mlx_xpm_file_to_image(game->mlx,
            "assets/floor.xpm", &game->floor.w, &game->floor.h);
    game->player.ptr = mlx_xpm_file_to_image(game->mlx,
            "assets/player.xpm", &game->player.w, &game->player.h);
    game->exit_c.ptr = mlx_xpm_file_to_image(game->mlx,
            "assets/exit_c.xpm", &game->exit_c.w, &game->exit_c.h);
	game->exit_o.ptr = mlx_xpm_file_to_image(game->mlx,
            "assets/exit_o.xpm", &game->exit_o.w, &game->exit_o.h);
    game->collectible.ptr = mlx_xpm_file_to_image(game->mlx,
            "assets/collectible.xpm", &game->collectible.w, &game->collectible.h);
        if (!game->wall.ptr || !game->floor.ptr || !game->player.ptr
            || !game->exit_c.ptr || !game->exit_o.ptr || !game->collectible.ptr)
            return (1);
    return (0);
}
