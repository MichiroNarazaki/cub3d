#include "../includes/main.h"
#include "../mms/mlx.h"

void my_make_line(t_game *game, t_line *line, int color)
{
	double a; //傾き
	double b; //切片
	int i;
	int x;
	int y;

	if (line->x_end == line->x_start) //y軸平衡
	{
		y = line->y_start;
		x = line->x_start;
		while (y < line->y_end)
		{
			game->img.data[x + (y - 1) * WIDTH] = color;
			y++;
		}
	}
	else if (line->x_end == line->x_start) //x軸平衡
	{
		x = line->x_start;
		y = line->y_start;
		while (x < line->x_end)
		{
			game->img.data[x + (y - 1) * WIDTH] = color;
			x++;
		}
	}
	else
	{
		a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
		b = line->y_start - (a * line->x_start);
		i = 0;
		while (line->x_start + i <= line->x_end)
		{
			x = (int)(line->x_start + i);
			y = (int)(a * (line->x_start + i) + b);
			game->img.data[x + (y - 1) * WIDTH] = color;
			i++;
		}
	}
}
