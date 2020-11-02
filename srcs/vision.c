//各自で適宜ヘッダーファイルの設定をしてください。
#include "../mms/mlx.h"
#include "../includes/main.h"

void my_vision(t_game *game, int color)
{
	double x;
	double y;
	t_line line;
	double dy;
	double dx;
	
	y = 100.0;
	x = 100.0;
	dy = 50.0;
	dx = 100.0;

	line.x_start = x;
	line.x_end = x + dx;
	line.y_start = y;
	line.y_end = y + dy;
	my_make_line(game, &line, color);
	line.y_end = y - dy;
	if(line.y_end < 0 )
	{
		printf("Error : line.y_end is minus");
		return;
	}
	my_make_line(game, &line, color);
}
