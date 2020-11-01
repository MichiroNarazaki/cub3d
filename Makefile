CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3d.a
OPTIONS = -L./opengl -lmlx -framework OpenGL -framework AppKit
SOURCES =	srcs/line.c \
			srcs/testmovement.c \
			srcs/vision.c \
			srcs/walls.c

all: $(NAME)

$(NAME):
		$(CC) $(OPTIONS) $(SOURCES) -o $(NAME)

fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: clean fclean all re
