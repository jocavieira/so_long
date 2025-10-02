# === Configurações ===
NAME = gnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c \
      get_next_line_utils.c
OBJ = $(SRC:.c=.o)
INC = -I .

# === Regras ===
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re