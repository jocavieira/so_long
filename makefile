# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 10:39:55 by jocarlo2          #+#    #+#              #
#    Updated: 2025/10/02 08:11:54 by jocarlo2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = clang
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

# Bibliotecas
LIBFT = -Llibft -lft
GNL = get_next_line/gnl.a
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: libft gnl $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(MLX) $(INC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

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
