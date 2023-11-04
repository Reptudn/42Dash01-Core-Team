SRCS = parse_file.c utils.c algorithm.c heatmap.c walkmap.c
SRC = $(addprefix src/, $(SRCS))
OBJ = $(SRCS:%.c=%.o)

NAME = marvin

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment

.PHONY: all clean fclean re

all: $(NAME)

run: all
	./$(NAME) maps/map4.txt

$(NAME): $(OBJ) src/main.c
	make -C libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)
	$(CC) $(CFLAGS) src/main.c $(NAME) -o $(NAME) -I . -I libft

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I . -I libft

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
