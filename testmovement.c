#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//各自で適宜ヘッダーファイルの設定をしてください。
#include "mms/mlx.h"

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17 //Exit program key code

//キーコードはwsl ubuntu仕様です。
//minilibx-linuxディレクトリ内の/test/mlx-testでそれぞれの環境のキーコードを確認してください。

#define KEY_ESC 65307
#define KEY_W 126 //上
#define KEY_A 123 //左
#define KEY_S 125 //下
#define KEY_D 124 //右

#define TILE_SIZE 32
#define ROWS 11
#define COLS 15
#define WIDTH COLS *TILE_SIZE
#define HEIGHT ROWS *TILE_SIZE

int g_player_x = 50; //初期位置
int g_player_y = 50; //初期位置
int g_key_flag = 1;

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
	int x_start;
	int y_start;
	int x_end;
	int y_end;
} t_line;

//赤いユーザの四角を描画している関数(多分)
void my_rec_put(t_game *game, int x, int y, int color)
{
	int x_end = x + 10; //10が四角の大きさを決定してる(辺の長さ)
	int y_end = y + 10; //10が四角の大きさを決定してる(辺の長さ)
	int y_tmp = y;
	while (x <= x_end)
	{
		y = y_tmp;
		while (y <= y_end)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, color);
			y++;
		}
		x++;
	}
}

void my_make_line(t_game *game, t_line *line, int color)
{
	int a; //傾き
	int b; //切片
	int i;

	a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
	b = line->y_start - (a * line->x_start);
	i = 0;
	while (line->x_start + i <= line->x_end)
	{
		mlx_pixel_put(game->mlx, game->win, line->x_start + i, a * (line->x_start + i) + b, color);
		i++;
	}
}

void my_vision(t_game *game, int x, int y, int color)
{
	t_line line;

	line.x_start = x;
	line.x_end = x + 30;
	line.y_start = y;
	line.y_end = y + 30;

	my_make_line(game,&line,color);
	line.y_end = y - 30;
	my_make_line(game,&line,color);
}

int deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
		g_player_y -= 10;
	else if (key_code == KEY_S)
		g_player_y += 10;
	else if (key_code == KEY_A)
		g_player_x -= 10;
	else if (key_code == KEY_D)
		g_player_x += 10;
	g_key_flag = 1;
	return (0);
}

int close(t_game *game)
{
	exit(0);
}

void window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
}

void img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int main_loop(t_game *game)
{
	if (g_key_flag == 1)
	{
		//	描画する
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
		my_rec_put(game, g_player_x, g_player_y, 0x00FF0000);
		my_vision(game, g_player_x, g_player_y, 0x00FFFFFF);
	}
	g_key_flag = 0;
	return (0);
}

int main(void)
{
	t_game game;

	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 1, &close, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}