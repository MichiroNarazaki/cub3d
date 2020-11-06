//各自で適宜ヘッダーファイルの設定をしてください。
#include "../mms/mlx.h"
#include "../includes/main.h"

int map[COLS][ROWS] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void draw_tile(t_img *img, int col, int row, int color)
{
	int x_start = col * TILE_SIZE;
	int y_start = row * TILE_SIZE;
	int x_end = x_start + TILE_SIZE; //10が四角の大きさを決定してる(辺の長さ)
	int y_end = y_start + TILE_SIZE; //10が四角の大きさを決定してる(辺の長さ)
	int i;
	t_line line;

	line.y_end = y_end;
	line.y_start = y_start;
	i = 0;
	while (x_start + (double)i <= x_end)
	{
		line.x_start = x_start + (double)i;
		line.x_end = line.x_start;
		my_make_line(img, &line, color);
		i++;
	}
}
//start < endの大小関係としないと表示されない
void my_walls(t_img *img, int color)
{
	int col;
	int row;

	col = 0;
	while (col < COLS)
	{
		row = 0;
		while (row < ROWS)
		{
			if (map[col][row] == 1)
				draw_tile(img, col, row, color);
			else if (map[col][row] == 0)
				draw_tile(img, col, row, 0x00ffffff);
			row++;
		}
		col++;
	}
}
