
#include "so_long.h"

void	render_sprts_util(t_data *data, t_sprt *s)
{
	t_sprt	*tmp;

	tmp = s;
	while (s)
	{
		if (s->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, s->img.mlx, s->v.x, s->v.y);
		s = s->next;
	}
}

void	free_sprts_util(t_data *data, t_sprt *s)
{
	t_sprt	*tmp;

	tmp = s;
	while (s)
	{
		if (s->img.mlx)
			mlx_destroy_image(data->mlx, s->img.mlx);
		s = s->next;
	}
}
