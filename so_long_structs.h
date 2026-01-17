/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:30:48 by jocarlo2          #+#    #+#             */
/*   Updated: 2026/01/14 08:36:39 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
#define SO_LONG_STRUCTS_H

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_count;
	int		player_x;
	int		player_y;
    char	prev_tile;
	int		exit_count;
	int		collect_count;
	int		collected;
	int		exit_reached;
    int     moves;
	
}	t_map;
typedef struct s_img
{
    void    *ptr;
    int     w;
    int     h;
}   t_img;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_map   map;
    t_img   wall;
    t_img   floor;
    t_img   player;
    t_img   exit_c;
    t_img   exit_o;
    t_img   collectible;
}   t_game;

#endif