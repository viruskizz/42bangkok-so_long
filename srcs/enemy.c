#include "so_long.h"

static t_sprt	*load_from_map(t_data *data);
static t_sprt	*new_monster(t_data *data, t_vtr v);
static void		move_enemies(t_data *data, t_sprt *e);


void	load_enemies(t_data *data)
{
	int		i;
	t_tile	ft;
	t_sprt	*e;
	t_sprt	*tmp;

	i = 0;
	data->enemies = NULL;
	tmp = load_from_map(data);
	while (i++ < ENEMY)
	{
		ft = random_free_tile(data, 0);
		e = new_monster(data, ft.v);
		if (data->enemies)
			tmp->next = e;
		else
			data->enemies = e;
		data->map.enemy++;
		tmp = e;
	}
}

void	render_enemies(t_data *data)
{
	t_sprt *e;

	e = data->enemies;
	while (e)
	{
		move_enemies(data, e);
		enemy_walking(data, e);
		if (e->img.mlx)
			mlx_put_image_to_window(data->mlx, data->win, e->img.mlx, e->v.x, e->v.y);
		e = e->next;
	}
}


static t_sprt	*load_from_map(t_data *data)
{
	int		gx;
	int		gy;
	t_sprt	*e;
	t_sprt	*tmp;

	gy = 0;
	data->enemies = NULL;
	tmp = data->enemies;
	while (gy < data->map.grid_y)
	{
		gx = 0;
		while (gx < data->map.grid_x)
		{
			if (data->map.tiles[gy][gx].type == 'M')
			{
				e = new_monster(data, (t_vtr){gx, gy});
				if (tmp)
					tmp->next = e;
				else
					data->enemies = e;
				tmp = e;
			}
			gx++;
		}
		gy++;
	}
	return (tmp);
}

static t_sprt	*new_monster(t_data *data, t_vtr v)
{
	t_sprt *e;

	e = malloc(sizeof(t_sprt));
	e->v = v;
	e->nv = v;
	e->animating = 0;
	e->act = ACT_STAND;
	e->face = data->frame % 4 + 1;
	e->next = NULL;
	e->img = set_img(data, ENEMY_STAND_FRONT_PATH);
	return (e);
}

static void	move_enemies(t_data *data, t_sprt *e)
{
	t_tile	nt;
	t_vtr	nv;
	t_vtr	mv;

	if (e->nv.x != e->v.x || e->nv.y != e->v.y)
	{
		mv = get_move_vtr(e->face, 1);
		nv = add_vtr(e->v, mv);
		e->v = nv;
		return;
	}
	mv = get_move_vtr(e->face, 0);
	nv = add_vtr(e->v, mv);
	nt = get_tile(data, nv);
	if (nt.type == '1')
	{
		e->face = data->stime % 4 + 1;
		return;
	}
	e->nv = nv;
}
