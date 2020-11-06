//各自で適宜ヘッダーファイルの設定をしてください。
#include "../mms/mlx.h"
#include "../includes/main.h"

// double g_player_deg = 0; //初期角度n°

// x,yはユーザの位置情報

void my_vision(t_img *img, int x, int y, int color)
{
	// t_vector player;
	t_vector camera;
	t_line line;
	double i;

	// player.dir = g_player_deg * (M_PI / 180);
	// camera.dir = player.dir + M_PI / 2;
 	camera.len = TILE_SIZE;//3dだと画面サイズ/2。だけど2dなので画面サイズ100としてcamera.lenは50と指定する
	i = 0;
	line.x_start = x;
	line.y_start = y;
	line.y_end = y + 2 * TILE_SIZE; //最初は定数
	while (i < camera.len)
	{
		line.x_end = x + i;
		my_make_line(img, &line, color);
		line.x_end = x - i;
		my_make_line(img, &line, color);
		i += 1;
	}
}

