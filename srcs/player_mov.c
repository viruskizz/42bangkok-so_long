/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 01:38:10 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/27 01:38:11 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_standing(t_data *data)
{
	t_sprt	p;

	data->player.act = ACT_STAND;
	p = data->player;
	if (p.act != ACT_STAND)
		return ;
	if (p.face == DIRCT_LEFT)
		data->player.img = set_img(data, SPRITE_STAND_LEFT_PATH);
	if (p.face == DIRCT_RIGHT)
		data->player.img = set_img(data, SPRITE_STAND_RIGHT_PATH);
	if (p.face == DIRCT_UP)
		data->player.img = set_img(data, SPRITE_STAND_UP_PATH);
	if (p.face == DIRCT_DOWN)
		data->player.img = set_img(data, SPRITE_STAND_DOWN_PATH);
}

void	player_walking(t_data *data)
{
	t_sprt	p;

	p = data->player;
	if (p.face == DIRCT_LEFT && p.v.x % 32 < 16)
		data->player.img = set_img(data, SPRITE_WALK_LEFT1_PATH);
	else if (p.face == DIRCT_LEFT)
		data->player.img = set_img(data, SPRITE_WALK_LEFT2_PATH);
	else if (p.face == DIRCT_RIGHT && p.v.x % 32 < 16)
		data->player.img = set_img(data, SPRITE_WALK_RIGHT1_PATH);
	else if (p.face == DIRCT_RIGHT)
		data->player.img = set_img(data, SPRITE_WALK_RIGHT2_PATH);
	else if (p.face == DIRCT_UP && p.v.y % 32 < 16)
		data->player.img = set_img(data, SPRITE_WALK_UP1_PATH);
	else if (p.face == DIRCT_UP)
		data->player.img = set_img(data, SPRITE_WALK_UP2_PATH);
	else if (p.face == DIRCT_DOWN && p.v.y % 32 < 16)
		data->player.img = set_img(data, SPRITE_WALK_DOWN1_PATH);
	else if (p.face == DIRCT_DOWN)
		data->player.img = set_img(data, SPRITE_WALK_DOWN2_PATH);
}

void	player_collect(t_data *data)
{
	data->player.img = set_img(data, SPRITE_KNEEL_PATH);
	data->player.animating += 1;
	if (data->player.animating == FRAME_RATE / 2)
	{
		data->player.act = ACT_STAND;
		data->player.animating = 0;
	}
}

void	player_moving(t_data *data)
{
	t_sprt	p;

	p = data->player;
	if (p.v.x == p.nv.x && p.v.y == p.nv.y)
		player_standing(data);
	if (data->player.act != ACT_WALK)
		return ;
	if (p.face == DIRCT_LEFT)
		data->player.v.x -= 2;
	if (p.face == DIRCT_RIGHT)
		data->player.v.x += 2;
	if (p.face == DIRCT_UP)
		data->player.v.y -= 2;
	if (p.face == DIRCT_DOWN)
		data->player.v.y += 2;
}

void	player_hurting(t_data *data)
{
	data->player.img = set_img(data, SPRITE_HURT_PATH);
	data->player.act = ACT_HURTING;
	data->player.animating += 1;
	if (data->player.animating == 20)
	{
		data->player.act = ACT_FALLEN;
		data->player.animating = 0;
	}
}
