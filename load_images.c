/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 09:56:35 by jocarlo2          #+#    #+#             */
/*   Updated: 2026/01/17 12:58:55 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  load_img(t_game *game, t_img *img, char *path)
{
        img->ptr = mlx_xpm_file_to_image(game->mlx, path, &img->w, &img->h);
        if (!img->ptr)
                return (1);
        img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len, &img->endian);
        return (0);
}

static unsigned int  get_pixel(t_img *img, int x, int y)
{
        return (*(unsigned int *)(img->addr + y * img->line_len + x * (img->bpp / 8)));
}

static void set_pixel(t_img *img, int x, int y, unsigned int color)
{
        *(unsigned int *)(img->addr + y * img->line_len + x * (img->bpp / 8)) = color;
}

#ifdef __LINUX__
static int  compose_over_floor(t_game *game, t_img *sprite)
{
        t_img           merged;
        unsigned int    key;
        int             x;
        int             y;

        merged.ptr = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
        if (!merged.ptr)
                return (1);
        merged.addr = mlx_get_data_addr(merged.ptr, &merged.bpp,
                        &merged.line_len, &merged.endian);
        key = get_pixel(sprite, 0, 0);
        y = 0;
        while (y < TILE_SIZE)
        {
                x = 0;
                while (x < TILE_SIZE)
                {
                        if (get_pixel(sprite, x, y) == key)
                                set_pixel(&merged, x, y, get_pixel(&game->floor, x, y));
                        else
                                set_pixel(&merged, x, y, get_pixel(sprite, x, y));
                        x++;
                }
                y++;
        }
        mlx_destroy_image(game->mlx, sprite->ptr);
        *sprite = merged;
        sprite->w = TILE_SIZE;
        sprite->h = TILE_SIZE;
        return (0);
}
#endif

int load_images(t_game *game)
{
        if (load_img(game, &game->wall, "assets/wall.xpm"))
                return (1);
        if (load_img(game, &game->floor, "assets/floor.xpm"))
                return (1);
        if (load_img(game, &game->player, "assets/player.xpm"))
                return (1);
        if (load_img(game, &game->exit_c, "assets/exit_c.xpm"))
                return (1);
        if (load_img(game, &game->exit_o, "assets/exit_o.xpm"))
                return (1);
        if (load_img(game, &game->collectible, "assets/collectible.xpm"))
                return (1);
#ifdef __LINUX__
        if (compose_over_floor(game, &game->player)
                || compose_over_floor(game, &game->exit_c)
                || compose_over_floor(game, &game->exit_o)
                || compose_over_floor(game, &game->collectible))
                return (1);
#endif
        return (0);
}
