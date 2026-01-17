/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:04:09 by jocarlo2          #+#    #+#             */
/*   Updated: 2026/01/14 08:23:39 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game("Error: mlx_init failed", game);
	game->win = mlx_new_window(game->mlx,
			game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
		exit_game("Error: mlx_new_window failed", game);
	if (load_images(game))
		exit_game("Error: failed to load images", game);
	draw_map(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, (int (*)())close_window, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		return (write(2, "Usage: ./so_long <map_file>\n", 28), 1);
	if (check_map(argv[1], &game.map))
		return (1);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}



