//各自で適宜ヘッダーファイルの設定をしてください。
#include "../mms/mlx.h"
#include "../includes/main.h"

int g_player_x = 2.5 * TILE_SIZE; //初期位置
int g_player_y = 2.5 * TILE_SIZE; //初期位置
int g_key_flag = 1;

int deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
		g_player_y -= TILE_SIZE;
	else if (key_code == KEY_S)
		g_player_y += TILE_SIZE;
	else if (key_code == KEY_A)
		g_player_x -= TILE_SIZE;
	else if (key_code == KEY_D)
		g_player_x += TILE_SIZE;
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
	if (g_key_flag == 1) //g_key_flagって何?
	{
		//	描画する
		my_walls(&(game->img), 0x00204030);
		// my_ceiling_tiles(&game->img, 0x00F0F080);
		my_rec_put(&(game->img), g_player_x, g_player_y, 0x00FF00F0);
		my_vision(&(game->img), g_player_x, g_player_y, 0x00303030);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
		// my_vision(game, g_player_x, g_player_y, 0x00FFFFFF);
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