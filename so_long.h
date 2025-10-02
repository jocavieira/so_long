/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:46:40 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/10/02 07:52:07 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "so_long_def.h"
#include "so_long_structs.h"
#include "get_next_line/get_next_line.h"
#include "libft/inc/libft.h"
#include "mlx/mlx.h"

char	**create_grid(char *file, t_map *map);
void	check_file(char *file);
int		is_rectangular(t_map *map);
int		is_surrounded(t_map *map);
int		validate_content(t_map *map);
void	floodfill(char **grid, int x, int y, t_map *map);
int		check_path(t_map *map);
int		check_map(char *file, t_map *map);
void	free_grid(char **grid);
char	**dup_grid(char **grid);
void	find_player(t_map *map);
int		load_images(t_game *game);
void	draw_map(t_game *game);
void	exit_game(char *msg, t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		key_hook(int keycode, t_game *game);
void    draw_tile(t_game *game, char c, int x, int y);
void	count_move(t_game *game);
void map_error_exit(char *msg, t_map *map);
int close_window(void *param);
#endif
