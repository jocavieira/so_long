/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:43:51 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/09/26 12:56:27 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_map(char *file)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	buffer = ft_strdup("");
	while ((line = get_next_line(fd)))
	{
		tmp = ft_strjoin(buffer, line);
		free(buffer);
		buffer = tmp;
		free(line);
	}
	close(fd);
	return (buffer);
}

char	**create_grid(char *file, t_map *map)
{
	char	*buffer;
	char	**grid;

	buffer = read_map(file);
	grid = ft_split(buffer, '\n');
	free(buffer);
	if (!grid)
		exit(1);
	map->height = 0;
	while (grid[map->height])
		map->height++;
	map->width = ft_strlen(grid[0]);
	return (grid);
}

