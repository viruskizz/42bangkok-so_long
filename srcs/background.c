#include "so_long.h"

static void	new_bg(t_data *data, t_tile t);

void	load_backgrounds(t_data *data)
{
	data->bg = NULL;
	grid_loop_util(data, &new_bg);
}

void	render_backgrounds(t_data *data)
{
	t_sprt	*bg;

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
	t_sprt	*bg;

	bg = data->bg;
	while (bg)
	{
		if (bg->img.mlx)
			mlx_destroy_image(data->mlx, bg->img.mlx);
		bg = bg->next;
	}
}

static void	new_bg(t_data *data, t_tile t)
{
	t_sprt	*bg;

	bg = malloc(sizeof(t_sprt));
	if (!bg)
		exit(1);
	bg->v = t.v;
	bg->type = '0';
	bg->img = set_img(data, OBJECT_GRASS_PATH);
	bg->next = NULL;
	if (!data->bg)
		data->bg = bg;
	else
		add_sprt_list(data->bg, bg);
}
