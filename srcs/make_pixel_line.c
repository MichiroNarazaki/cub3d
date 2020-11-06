#include "../mms/mlx.h"
#include "../includes/main.h"

void make_pixel_line(t_game *game, t_line *line, int color)
{
	double a; //傾き
	double b; //切片
	double i;
	int x;
	int y;

	if (line->x_end == line->x_start) //y軸平衡
	{
		y = line->y_start;
		x = line->x_start;
		while (y < line->y_end)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, color);
			y++;
		}
	}
	else if (line->y_end == line->y_start) //x軸平衡
	{
		y = line->y_start;
		x = line->x_start;
		while (x < line->x_end)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, color);
			x++;
		}
	}
	else
	{
		a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
		b = line->y_start - (a * line->x_start);
		i = 0;
		if (a > 0)
		{
			while ((int)line->x_start + i <= (int)line->x_end)
			{
				x = (int)(line->x_start + (double)i);
				y = (int)(a * x + b);
				if ((x + (y - 1) * WIDTH) < 0)
				{
					printf("Error : Array index is minus\n");
					return;
				}
				mlx_pixel_put(game->mlx, game->win, x, y, color);
				i += 0.5;
			}
			// printf("%lf\n", i);
		}
		else
		{
			while ((int)line->x_end + i <= (int)line->x_start)
			{
				x = (int)(line->x_end + i);
				y = (int)(a * x + b);
				if ((x + (y - 1) * WIDTH) < 0)
				{
					printf("Error : Array index is minus\n");
					return;
				}
				mlx_pixel_put(game->mlx, game->win, x, y, color);
				i += 0.5;
			}
			// printf("%lf\n", i);
		}
	}
}
// double a; //傾き
// double b; //切片
// int i;

// a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
// b = line->y_start - (a * line->x_start);
// i = 0;
// while (line->x_start + i <= line->x_end)
// {
// 	mlx_pixel_put(game->mlx, game->win, (int)(line->x_start + i), (int)(a * (line->x_start + i) + b), color);
// 	i++;
// }