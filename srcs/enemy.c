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

void	enemy_walking(t_data *data, t_sprt *e)
{
	mlx_destroy_image(data->mlx, e->img.mlx);
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

void	move_enemies(t_data *data, t_sprt *e)
{
	t_tile	nt;
	t_vtr	nv;
	t_vtr	mv;

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
	enemy_walking(data, e);
}
