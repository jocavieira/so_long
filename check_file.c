/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:27:28 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/09/26 12:26:11 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_file(char *file)
{
    int fd;
    int i;

    i = ft_strlen(file);
    if (i < 5 || ft_strncmp(&file[i - 4], ".ber", 4))
    {
        write(2, "Error\nFile must have .ber extension\n", 38);
        exit(1);
    }
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\nCannot open file\n", 24);
        exit(1);
    }
    close(fd);
}