#include "so_long.h"

t_tile	*new_bg(t_data *data, int x, int y)
{
	t_tile	*t;

	t = malloc(sizeof(t_tile));
	if (!t)
		exit(1);
	t->v.x = x;
	t->v.y = y;
	t->type = '0';
	t->img = set_img(data, OBJECT_GRASS_PATH);
	t->next = NULL;
	return (t);
}

void	load_backgrounds(t_data *data)
{
	int		x;
	int		y;
	t_tile	*bg;
	t_tile	*tmp;

	x = 0;
	y = 0;
	data->bg = NULL;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			bg = new_bg(data, x, y);
			if (data->bg)
				tmp->next = bg;
			else
				data->bg = bg;
			tmp = bg;
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

void	render_backgrounds(t_data *data)
{
	t_tile	*bg;

	bg = data->bg;
	while (bg)
	{
		if (bg->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, bg->img.mlx, bg->v.x, bg->v.y);
		bg = bg->next;
	}
}

void	free_backgrounds(t_data *data)
{
	t_tile	*bg;

	bg = data->bg;
	while (bg)
	{
		if (bg->img.mlx)
			mlx_destroy_image(data->mlx, bg->img.mlx);
		bg = bg->next;
	}
}
