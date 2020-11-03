#include "../mms/mlx.h"
#include "../includes/main.h"

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
