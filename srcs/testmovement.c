//各自で適宜ヘッダーファイルの設定をしてください。
#include "../mms/mlx.h"
#include "../includes/main.h"

int g_player_x = 150; //初期位置
int g_player_y = 150; //初期位置
int g_key_flag = 1;



//原点O(x,y)
void my_rec_put(t_game *game, int x, int y, int color)
{
	int x_start = x - (SIDE / 2);
	int y_start = y - (SIDE / 2);
	int x_end = x + (SIDE / 2); //10が四角の大きさを決定してる(辺の長さ)
	int y_end = y + (SIDE / 2); //10が四角の大きさを決定してる(辺の長さ)
	int y_tmp = y_start;

	while (x_start <= x_end)
	{
		y_start = y_tmp;
		while (y_start <= y_end)
		{
			mlx_pixel_put(game->mlx, game->win, x_start, y_start, color);
			y_start++;
		}
		x_start++;
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
		my_walls(game,0x00F0F080);
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