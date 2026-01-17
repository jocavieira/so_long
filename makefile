# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocarlo2 <jocarlo2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 10:39:55 by jocarlo2          #+#    #+#              #
#    Updated: 2026/01/17 12:48:10 by jocarlo2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = check_file.c \
      load_map.c \
      validate_map.c \
      validate_map_utils.c \
      main.c \
      so_long.c \
      draw_map.c \
      load_images.c \
      error.c

OBJ = $(SRC:.c=.o)

# Includes
INC = -I. -Ilibft/inc -Iget_next_line

# Detectar SO
UNAME_S = $(shell uname -s)
SOCFLAGS =

ifeq ($(UNAME_S), Linux)
	SOCFLAGS = -D__LINUX__
	MLX = -Lminilibx-linux -lmlx -lX11 -lXext -lm
endif
ifeq ($(UNAME_S), Darwin)
	SOCFLAGS = -D__MACOS__
	MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif


# Bibliotecas
LIBFT = -Llibft -lft
GNL = get_next_line/gnl.a

all: libft gnl $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SOCFLAGS) $(OBJ) $(LIBFT) $(GNL) $(MLX) $(INC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(SOCFLAGS) $(INC) -c $< -o $@

# Compila libft
libft:
	$(MAKE) -C libft

# Compila get_next_line
gnl:
	$(MAKE) -C get_next_line

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C get_next_line clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re libft gnl
