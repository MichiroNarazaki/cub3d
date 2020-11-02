#include "../includes/main.h"
#include "../mms/mlx.h"

void my_make_line(t_img *img, t_line *line, int color)
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
			img->data[x + (y - 1) * WIDTH] = color;
			y++;
		}
	}
	else if (line->y_end == line->y_start) //x軸平衡
	{
		x = line->x_start;
		y = line->y_start;
		while (x < line->x_end)
		{
			img->data[x + (y - 1) * WIDTH] = color;
			x++;
		}
	}
	else
	{
		a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
		b = line->y_start - (a * line->x_start);
		i = 0;
		while ((int)line->x_start + i <= (int)line->x_end)
		{
			x = (int)(line->x_start + (double)i);
			y = (int)(a * (line->x_start + (double)i) + b);
			if ((x + (y - 1) * WIDTH) < 0)
			{
				printf("Error : Array index is minus\n");
				return;
			}
			img->data[x + (y - 1) * WIDTH] = color; //0 + (0 -1)*WIDTHにアクセスしているからだめ
			i++;
		}
	}
}
