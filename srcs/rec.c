#include "../mms/mlx.h"
#include "../includes/main.h"

//原点O(x,y)
void my_rec_put(t_img *img, int x, int y, int color)
{
	t_line line;
	int i;
	int x_init;

	i = 0;
	x_init = x - (SIDE / 2);
	line.y_start = y - (SIDE / 2);
	line.y_end = y + (SIDE / 2);
	while (line.x_start < x + (SIDE / 2))
	{
		line.x_start = x_init + i;
		line.x_end = line.x_start;
		my_make_line(img, &line, color);
		i++;
	}
}