all:
	gcc -L./opengl -lmlx -framework OpenGL -framework AppKit testmovement.c
	./a.out
