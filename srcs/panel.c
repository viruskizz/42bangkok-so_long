#include "so_long.h"

void	load_panel(t_data *data)
{
	int		gx;
	int		gy;
	t_sprt	*bg;

	gx = 0;
	gy = data->map.grid_y;
	bg = data->panel.bg;
	data->panel.h = TILE_SIZE;
	data->panel.w = data->map.width;
	data->panel.v.x = 0;
	data->panel.v.y = data->map.height;
	data->panel.bg = NULL;
	while (gx < data->map.grid_x)
	{
		bg = malloc(sizeof(t_sprt));
		bg->img = set_img(data, OBJECT_GRASS_PATH);
		bg->v.x = gx * TILE_SIZE;
		bg->v.y = gy * TILE_SIZE;
		bg->next = NULL;
		if (!data->panel.bg)
			data->panel.bg = bg;
		else
			add_sprt_list(data->panel.bg, bg);
		gx++;
	}
}

void	render_panel(t_data *data)
{
	t_sprt	*bg;
	t_sprt	*s;

	bg = data->panel.bg;
	s = data->panel.score;
	while (bg)
	{
		if (bg->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, bg->img.mlx, bg->v.x, bg->v.y);
		bg = bg->next;
	}

}
