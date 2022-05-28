#include "so_long.h"

static void	init_number(t_data *data, int i);

void	load_score(t_data *data)
{
	int		i;

	data->panel.score = NULL;
	i = 0;
	while (i < 4)
		init_number(data, i++);
}

void	render_score(t_data *data)
{
	t_sprt	*s;

	s = data->panel.score;
	while (s)
	{
		if (s->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, s->img.mlx, s->v.x, s->v.y);
		s = s->next;
	}
}

void	update_score(t_data *data)
{
	char	*txt;
	int		len;
	int		i;
	t_sprt	*s;

	txt = ft_itoa(data->player.moved);
	len = ft_strlen(txt);
	s = data->panel.score;
	i = 0;
	while (i < SCORE_LEN)
	{
		if (i == 3 && len >= 1)
			s->img = get_number_img(data, txt[len - 1]);
		else if (i == 2 && len >= 2)
			s->img = get_number_img(data, txt[len - 2]);
		else if (i == 1 && len >= 3)
			s->img = get_number_img(data, txt[len - 3]);
		else if (i == 0 && len == 4)
			s->img = get_number_img(data, txt[len - 4]);
		i++;
		s = s->next;
	}
}

static void	init_number(t_data *data, int i)
{
	int		sx;
	t_sprt	*s;

	// sx = (data->w / 2) - TILE_SIZE * 2;
	sx = 0;
	s = malloc(sizeof(t_sprt));
	s->v.x = sx + i * TILE_SIZE;
	s->v.y = data->map.height;
	s->img = get_number_img(data, '0');
	s->next = NULL;
	if (!data->panel.score)
		data->panel.score = s;
	else
		add_sprt_list(data->panel.score, s);
}
