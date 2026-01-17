/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:44:06 by jocarlo2          #+#    #+#             */
/*   Updated: 2026/01/14 07:37:19 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(char *file, t_map *map)
{
    check_file(file);
    map->grid = create_grid(file, map);
    map->player_count = 0;
    map->exit_count = 0;
    map->collect_count = 0;
    map->collected = 0;
    map->exit_reached = 0;
    map->moves = 0;
    if (is_rectangular(map))
    {
        free_grid(map->grid);
        map->grid = NULL;
        write(2, "Error\nMap is not rectangular\n", 30);
        return (1);
    }
    if (is_surrounded(map))
    {
        free_grid(map->grid);
        map->grid = NULL;
        write(2, "Error\nMap is not surrounded by walls\n", 39);
        return (1);
    }
    if (validate_content(map))
    {
        free_grid(map->grid);
        map->grid = NULL;
        write(2, "Error\nmap must have 1 player, 1 exit, and at least 1 collectible\n", 67);
        return (1);
    }
    if (check_path(map))
    {
        free_grid(map->grid);
        map->grid = NULL;
        write(2, "Error\nNo valid path to collect all items and reach the exit\n", 62);
        return (1);
    }
    map->collected = 0;
    map->exit_reached = 0;
    return (0);
}

int is_rectangular(t_map *map)
{
    int y;
    y = 0;
    while (map->grid[y])
    {
        if ((int)ft_strlen(map->grid[y]) != map->width)
            return (1);
        y++;
    }
    return (0);
}

int is_surrounded(t_map *map)
{
    int x;
    int y;
    
    y = 0;
    while (map->grid[y])
    {
        x = 0;
        while (x < map->width)
        {
            if ((y == 0 || y == map->height-1 || x == 0 || x == map->width-1) 
                && map->grid[y][x] != '1')
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}

int validate_content(t_map *map)
{
    int y;
    int x;
    
    y = 0;
    while (map->grid[y])
    {
        x = 0;
        while (map->grid[y][x])
        {
            if (map->grid[y][x] == 'P')
                map->player_count++;
            else if (map->grid[y][x] == 'E')
                map->exit_count++;
            else if (map->grid[y][x] == 'C')
                map->collect_count++;
            else if (map->grid[y][x] != '0' && map->grid[y][x] != '1')
                return (1);
            x++;
        }
        y++;
    }
    if (map->player_count != 1 || map->exit_count != 1 || map->collect_count < 1)
        return (1);
    return (0);
}

int check_path(t_map *map)
{
    char **copy;

    copy = dup_grid(map->grid);
    if (!copy)
         map_error_exit("Malloc failed", map);
    find_player(map);
    floodfill(copy, map->player_x, map->player_y, map);
    free_grid(copy);
    if (map->collected != map->collect_count || !map->exit_reached)
        return (1);
    return (0);
}
