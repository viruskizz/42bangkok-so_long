#include "so_long.h"

void	enemy_walking(t_data *data, t_sprt *e)
{
	if (e->face == DIRCT_LEFT && e->v.x % 32 < 16)
		e->img = set_img(data, ENEMY_WALK_LEFT1_PATH);
	else if (e->face == DIRCT_LEFT)
		e->img = set_img(data, ENEMY_WALK_LEFT2_PATH);
	else if (e->face == DIRCT_RIGHT && e->v.x % 32 < 16)
		e->img = set_img(data, ENEMY_WALK_RIGHT1_PATH);
	else if (e->face == DIRCT_RIGHT)
		e->img = set_img(data, ENEMY_WALK_RIGHT2_PATH);
	else if (e->face == DIRCT_UP && e->v.y % 32 < 16)
		e->img = set_img(data, ENEMY_WALK_UP1_PATH);
	else if (e->face == DIRCT_UP)
		e->img = set_img(data, ENEMY_WALK_UP2_PATH);
	else if (e->face == DIRCT_DOWN && e->v.y % 32 < 16)
		e->img = set_img(data, ENEMY_WALK_DOWN1_PATH);
	else if (e->face == DIRCT_DOWN)
		e->img = set_img(data, ENEMY_WALK_DOWN2_PATH);
}
