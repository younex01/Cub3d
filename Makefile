NAME=cub3d
CC=gcc
CFLAGS=-Wall -Werror -Wextra
LIBS=-lmlx -framework OpenGL -framework AppKit
IDIR=./includes
DEPS=./includes/cub3d.h
SRC=./srcs/main.c ./srcs/raycast.c ./srcs/draw.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -I$(IDIR) -o $(NAME)

%.o : %.c $(DEPS)
	$(CC) -c $(CFLAGS) $< -I$(IDIR) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
