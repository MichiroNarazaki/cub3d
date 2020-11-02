//各自で適宜ヘッダーファイルの設定をしてください。
#include "../mms/mlx.h"
#include "../includes/main.h"


//start < endの大小関係としないと表示されない
void my_walls(t_img *img, int color)
{
	t_line line_1;
	t_line line_2;
	t_line line_3;

	line_1.x_start = 200.0;
	line_1.y_start = 200.0;
	line_1.x_end = 500.0;
	line_1.y_end = 200.0;

	line_2.x_start = 500.0;
	line_2.y_start = 200.0;
	line_2.x_end = 600.0;
	line_2.y_end = 400.0;

	line_3.x_start = 200.0;
	line_3.y_start = 200.0;
	line_3.x_end = 600.0;
	line_3.y_end = 400.0;

	my_make_line(img, &line_1, color);
	my_make_line(img, &line_2, color);
	my_make_line(img, &line_3, color);
}
