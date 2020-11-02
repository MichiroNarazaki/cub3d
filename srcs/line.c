#include "../includes/main.h"
#include "../mms/mlx.h"

// void my_rectangle(t_game *game)
// {
// 	int i;

// 	i = 0;
// 	while (i < 2000)
// 	{
// 		game->img.data[i] = 0x00c9e8;
// 		i++;
// 	}
// }

void my_make_line(t_game *game, t_line *line, int color)
{
	double a; //傾き
	double b; //切片
	int i;
	int x;
	int y;

	a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
	b = line->y_start - (a * line->x_start);
	i = 0;
	while (line->x_start + i <= line->x_end)
	{
		x = (int)(line->x_start + i);
		y = (int)(a * (line->x_start + i) + b);
		game->img.data[x + (y - 1) * WIDTH]=color;
		i++;
	}
}

// x = x;
// y = (y-1)*WIDTH;

// void my_make_line(t_game *game, t_line *line, int color)
// {
// 	double a; //傾き
// 	double b; //切片
// 	int i;

// 	a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
// 	b = line->y_start - (a * line->x_start);
// 	i = 0;
// 	while (line->x_start + i <= line->x_end)
// 	{
// 		mlx_pixel_put(game->mlx, game->win, (int)(line->x_start + i), (int)(a * (line->x_start + i) + b), color);
// 		i++;
// 	}
// }