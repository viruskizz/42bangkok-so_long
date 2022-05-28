#include "so_long.h"

static void	new_enemy(t_data *data, t_tile t);
static void	move_enemies(t_data *data, t_sprt *e);

void	load_enemies(t_data *data)
{
	data->enemies = NULL;
	grid_loop_util(data, &new_enemy);
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

static void	new_enemy(t_data *data, t_tile t)
{
	t_sprt *e;

	if (t.type != 'M')
		return ;
	e = malloc(sizeof(t_sprt));
	e->v = t.v;
	e->nv = t.v;
	e->animating = 0;
	e->act = ACT_STAND;
	e->face = data->frame % 4 + 1;
	e->next = NULL;
	e->img = set_img(data, ENEMY_STAND_FRONT_PATH);
	if (!data->enemies)
		data->enemies = e;
	else
		add_sprt_list(data->enemies, e);
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
