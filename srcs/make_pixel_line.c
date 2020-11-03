#include "../mms/mlx.h"
#include "../includes/main.h"

void make_pixel_line(t_game *game, t_line *line, int color)
{
	double a; //傾き
	double b; //切片
	int i;

	a = ((line->y_end - line->y_start) / (line->x_end - line->x_start));
	b = line->y_start - (a * line->x_start);
	i = 0;
	while (line->x_start + i <= line->x_end)
	{
		mlx_pixel_put(game->mlx, game->win, (int)(line->x_start + i), (int)(a * (line->x_start + i) + b), color);
		i++;
	}
}