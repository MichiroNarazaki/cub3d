#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17 //Exit program key code

//キーコードはwsl ubuntu仕様です。
//minilibx-linuxディレクトリ内の/test/mlx-testでそれぞれの環境のキーコードを確認してください。

#define KEY_ESC 65307
#define KEY_W 126 //上
#define KEY_A 123 //左
#define KEY_S 125 //下
#define KEY_D 124 //右

// #define TILE_SIZE 32
#define TILE_SIZE 64
#define ROWS 5
#define COLS 5
#define WIDTH COLS *TILE_SIZE
#define HEIGHT ROWS *TILE_SIZE

#define SIDE 20
#define ORIGIN_X 100.0
#define ORIGIN_Y 100.0

typedef struct s_img
{
	void *img;
	int *data; //imgの本体

	int size_l;
	int bpp;
	int endian;
} t_img;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_img img;
} t_game;

typedef struct s_line
{
	double x_start;
	double y_start;
	double x_end;
	double y_end;
} t_line;

void my_vision(t_img *img, int color);
void my_make_line(t_img *img, t_line *line, int color);
void my_walls(t_img *img, int color);
void my_rec_put(t_img *img, int color);
void my_ceiling(t_img *img);



