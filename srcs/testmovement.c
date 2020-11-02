//各自で適宜ヘッダーファイルの設定をしてください。
#include "../mms/mlx.h"
#include "../includes/main.h"

int g_player_x = 150; //初期位置
int g_player_y = 150; //初期位置
int g_key_flag = 1;

//原点O(x,y)
void my_rec_put(t_img *img, int color)
{
	double x = ORIGIN_X;
	double y = ORIGIN_Y;
	double x_start = x - (SIDE / 2);
	double y_start = y - (SIDE / 2);
	double x_end = x + (SIDE / 2); //10が四角の大きさを決定してる(辺の長さ)
	double y_end = y + (SIDE / 2); //10が四角の大きさを決定してる(辺の長さ)
	int i;
	t_line line;

	line.y_end = y_end;
	line.y_start = y_start;
	i = 0;
	while (x_start + (double)i <= x_end)
	{
		line.x_start = x_start + (double)i;
		line.x_end = x_start + (double)i;
		my_make_line(img, &line, color);
		i++;
	}
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

void img_init(t_img *img, t_game *game)
{
	img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
}

int main_loop(t_game *game)
{
	t_img wall;

	img_init(&wall,game);
	if (g_key_flag == 1) //g_key_flagって何?
	{
		//	描画する
		my_walls(&wall, 0x00F0F080);
		my_rec_put(&(game->img), 0x00FF00F0);
		my_vision(&(game->img), 0x00FFFFFF);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, g_player_x, g_player_y);
		mlx_put_image_to_window(game->mlx, game->win, wall.img, 300, 300);
	}
	g_key_flag = 0;
	return (0);
}

int main(void)
{
	t_game game;

	window_init(&game);
	img_init(&game.img, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 1, &close, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}