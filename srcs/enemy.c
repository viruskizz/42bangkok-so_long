/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:58:47 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 22:58:48 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_enemies(t_data *data, t_sprt *e);
static void	enemy_walking(t_data *data, t_sprt *e);

void	render_enemies(t_data *game)
{
	t_sprt	*e;

	e = game->enemies;
	while (e)
	{
		move_enemies(game, e);
		enemy_walking(game, e);
		if (e->img.mlx)
			mlx_put_image_to_window(
				game->mlx, game->win, e->img.mlx, e->v.x, e->v.y);
		e = e->next;
	}
}

void	respawn_enemies(t_data *game)
{
	t_tile	t;

	if (game->map.enemy >= ENEMY)
		return ;
	t = random_free_tile(game, FRAME_RATE / 2, game->map.enemy);
	t.type = 'M';
	new_enemy(game, t);
	game->map.enemy++;
}

static void	enemy_walking(t_data *data, t_sprt *e)
{
	int		is_step;

	is_step = data->frame % FRAME_RATE < FRAME_RATE / 2;
	mlx_destroy_image(data->mlx, e->img.mlx);
	if (e->face == DIRCT_LEFT && is_step)
		e->img = set_img(data, ENEMY_WALK_LEFT1_PATH);
	else if (e->face == DIRCT_LEFT)
		e->img = set_img(data, ENEMY_WALK_LEFT2_PATH);
	else if (e->face == DIRCT_RIGHT && is_step)
		e->img = set_img(data, ENEMY_WALK_RIGHT1_PATH);
	else if (e->face == DIRCT_RIGHT)
		e->img = set_img(data, ENEMY_WALK_RIGHT2_PATH);
	else if (e->face == DIRCT_UP && is_step)
		e->img = set_img(data, ENEMY_WALK_UP1_PATH);
	else if (e->face == DIRCT_UP)
		e->img = set_img(data, ENEMY_WALK_UP2_PATH);
	else if (e->face == DIRCT_DOWN && is_step)
		e->img = set_img(data, ENEMY_WALK_DOWN1_PATH);
	else if (e->face == DIRCT_DOWN)
		e->img = set_img(data, ENEMY_WALK_DOWN2_PATH);
}

static void	move_enemies(t_data *data, t_sprt *e)
{
	t_tile	nt;
	t_vtr	nv;
	t_vtr	mv;

	if (data->frame % 2 == 0)
		return ;
	if (e->nv.x != e->v.x || e->nv.y != e->v.y)
	{
		mv = get_move_vtr(e->face, 1);
		nv = add_vtr(e->v, mv);
		e->v = nv;
		return ;
	}
	mv = get_move_vtr(e->face, 0);
	nv = add_vtr(e->v, mv);
	nt = get_tile(data, nv);
	if (nt.type == '1')
	{
		e->face = data->stime % 4 + 1;
		return ;
	}
	e->nv = nv;
}
