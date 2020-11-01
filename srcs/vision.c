//各自で適宜ヘッダーファイルの設定をしてください。
#include "../mms/mlx.h"
#include "../includes/main.h"

void my_vision(t_game *game, int x, int y, int color)
{
	t_line line;
	double dy = 50.0;
	double dx = 100.0;

	line.x_start = x;
	line.x_end = x + dx;
	line.y_start = y;
	line.y_end = y + dy;
	my_make_line(game, &line, color);
	line.y_end = y - dy;
	my_make_line(game, &line, color);
}
