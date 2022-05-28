/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:02:31 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 23:02:32 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_player(t_data *data, t_tile t)
{
	t_sprt	p;

	if (t.type != 'P')
		return ;
	p.type = t.type;
	p.v = t.v;
	p.nv = p.v;
	p.animating = 0;
	p.act = ACT_STAND;
	p.face = DIRCT_DOWN;
	p.item = 0;
	p.moved = 0;
	p.img = set_img(data, SPRITE_STAND_DOWN_PATH);
	data->player = p;
}

void	new_enemy(t_data *data, t_tile t)
{
	t_sprt	*e;

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

void	new_obj(t_data *data, t_tile t)
{
	t_sprt	*obj;

	if (t.type != '0')
	{
		obj = malloc(sizeof(t_sprt));
		obj->v = t.v;
		obj->type = t.type;
		if (t.type == 'C')
			obj->img = set_img(data, OBJECT_ITEM_PATH);
		else if (t.type == '1')
			obj->img = set_img(data, OBJECT_WALL_PATH);
		else if (t.type == 'E')
			obj->img = set_img(data, OBJECT_EXIT_PATH);
		obj->next = NULL;
		if (!data->objs)
			data->objs = obj;
		else
			add_sprt_list(data->objs, obj);
	}
}

void	new_bg(t_data *data, t_tile t)
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
