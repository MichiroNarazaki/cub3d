#include "../mms/mlx.h"
#include "../includes/main.h"

void my_ceiling(t_img *img)
{
	t_line line;
	int sky = 0x0030b9f0;
	int floor = 0x001f7f1f;

	line.x_start = 0;
	line.y_start = 0;
	line.y_end = HEIGHT / 2;
	while (line.x_start <= WIDTH)
	{
		line.x_end = line.x_start;
		my_make_line(img, &line, sky);
		line.x_start++;
	}
	line.x_start = 0;
	line.y_start = HEIGHT / 2;
	line.y_end = HEIGHT;
	while (line.x_start <= WIDTH)
	{
		line.x_end = line.x_start;
		my_make_line(img, &line, floor);
		line.x_start++;
	}
}