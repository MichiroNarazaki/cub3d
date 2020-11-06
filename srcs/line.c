#include "../includes/main.h"
#include "../mms/mlx.h"

void my_make_line(t_img *img, t_line *line, int color)
{
	double a; //傾き
	double b; //切片
	double i;
	double x;
	double y;
	int index;

	if (line->x_end == line->x_start) //y軸平衡
	{
		y = line->y_start;
		x = line->x_start;
		while (y < line->y_end)
		{
			if (0 > x || x > WIDTH || 0 > y || y > HEIGHT)
			{
				y += 1;
				continue;
			}
			index = (int)(x + (y - 1) * WIDTH);
			img->data[index] = color;
			y += 1;
		}
	}
	else if (line->y_end == line->y_start) //x軸平衡
	{
		x = line->x_start;
		y = line->y_start;
		while (x < line->x_end)
		{
			if (0 > x || x > WIDTH || 0 > y || y > HEIGHT)
			{
				x += 1;
				continue;
			}
			index = (int)(x + (y - 1) * WIDTH);
			img->data[index] = color;
			x += 1;
		}
	}
	else
	{
		a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
		b = line->y_start - (a * line->x_start);
		i = 0;
		if (line->x_start < line->x_end)
		{

			while ((int)line->x_start + i <= (int)line->x_end)
			{
				x = (int)(line->x_start + (double)i);
				if (0 > x || x > WIDTH)
				{
					i+=1;
					continue;
				}
				y = (int)(a * x + b);
				if (0 > y || y > HEIGHT)
				{
					i+=1;
					continue;
				}
				index = x + (y - 1) * WIDTH;
				if (index < 0 || WIDTH * HEIGHT <= index)
				{
					i++;
					printf("Error : Array index is out of definition.\n");
					continue;
				}
				img->data[index] = color; //0 + (0 -1)*WIDTHにアクセスしているからだめ
				i+=1;
			}
		}
		else
		{
			while ((int)line->x_end <= (int)line->x_start - i)
			{
				x = (int)(line->x_start - (double)i);
				if (0 > x || x > WIDTH)
				{
					i+=1;
					continue;
				}
				y = (int)(a * x + b);
				if (0 > y || y > HEIGHT)
				{
					i+=1;
					continue;
				}
				index = x + (y - 1) * WIDTH;
				if (index < 0 || WIDTH * HEIGHT <= index)
				{
					i+=1;
					printf("Error : Array index is out of definition.\n");
					continue;
				}
				img->data[index] = color; //0 + (0 -1)*WIDTHにアクセスしているからだめ
				i+=1;
			}
		}
	}
}
