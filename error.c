/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:23:47 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/10/02 07:51:54 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_error_exit(char *msg, t_map *map)
{
    if (map && map->grid)
        free_grid(map->grid);
    write(2, "Error\n", 6);
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(1);
}
void free_images(t_game *game)
{
	if (game->wall.ptr)
		mlx_destroy_image(game->mlx, game->wall.ptr);
	if (game->floor.ptr)
		mlx_destroy_image(game->mlx, game->floor.ptr);
	if (game->player.ptr)
		mlx_destroy_image(game->mlx, game->player.ptr);
	if (game->exit_c.ptr)
		mlx_destroy_image(game->mlx, game->exit_c.ptr);
	if (game->exit_o.ptr)
		mlx_destroy_image(game->mlx, game->exit_o.ptr);
	if (game->collectible.ptr)
		mlx_destroy_image(game->mlx, game->collectible.ptr);
}
void free_grid(char **grid)
{
    int i;

	i = 0;
    if (!grid) 
        return;
    while (grid[i])
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}
void	exit_game(char *msg, t_game *game)
{
	if (game)
	{
		if (game->map.grid)
			free_grid(game->map.grid);
		free_images(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
#ifdef __linux__
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
#endif
	}
	if (msg)
	{
		write(1, msg, ft_strlen(msg));
		write(1, "\n", 1);
	}
	exit(0);
}
int close_window(void *param)
{
    t_game *game = (t_game *)param;
    exit_game("Too hard for you?", game);
    return (0);
}