/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:00:21 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/09/28 13:51:01 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEF_H
# define SO_LONG_DEF_H

#define TILE_SIZE 32

/* Keycodes for macOS */
#ifdef __MACOS__
# define ESC 53
# define W   13
# define A    0
# define S    1
# define D    2
#endif

/* Keycodes for Linux */
#ifdef __LINUX__
# define ESC 65307
# define W   119
# define A   97
# define S   115
# define D   100
#endif

#endif

