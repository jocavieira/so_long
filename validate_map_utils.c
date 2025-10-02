/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:52:34 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/10/02 07:27:04 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **dup_grid(char **grid)
{
    int y;
    int height;
    char **copy;
    
    y = 0;
    height = 0;
    while (grid[height])
        height++;
    copy = malloc(sizeof(char*) * (height + 1));
    if (!copy) 
    return NULL;
    while (y < height)
    {
        copy[y] = ft_strdup(grid[y]);
        if (!copy[y])
        {
            free_grid(copy);
            return NULL;
        }
        y++;
    }
    copy[y] = NULL;
    return copy;
}

void find_player(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->grid[i][j] == 'P')
            {
                map->player_x = j;
                map->player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}

void floodfill(char **grid, int x, int y, t_map *map)
{
    if (x < 0 || y < 0 || !grid[y] || !grid[y][x] || grid[y][x] == '1' || grid[y][x] == 'V')
        return;
    if (grid[y][x] == 'C')
        map->collected++;
    if (grid[y][x] == 'E')
        map->exit_reached = 1;
    grid[y][x] = 'V';
    floodfill(grid, x+1, y, map);
    floodfill(grid, x-1, y, map);
    floodfill(grid, x, y+1, map);
    floodfill(grid, x, y-1, map);
}
