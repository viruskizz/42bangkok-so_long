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

void	sprt_standing(t_data *data)
{
	t_sprt	s;

	data->sprt.act = ACT_STAND;
	s = data->sprt;
	if (s.act != ACT_STAND)
		return ;
	if (s.face == DIRCT_LEFT)
		data->sprt.img = set_img(data, SPRITE_STAND_LEFT_PATH);
	if (s.face == DIRCT_RIGHT)
		data->sprt.img = set_img(data, SPRITE_STAND_RIGHT_PATH);
	if (s.face == DIRCT_UP)
		data->sprt.img = set_img(data, SPRITE_STAND_UP_PATH);
	if (s.face == DIRCT_DOWN)
		data->sprt.img = set_img(data, SPRITE_STAND_DOWN_PATH);
}

void	sprt_walking(t_data *data)
{
	t_sprt	s;

	s = data->sprt;
	if (s.face == DIRCT_LEFT && s.x % 32 < 16)
		data->sprt.img = set_img(data, SPRITE_WALK_LEFT1_PATH);
	else if (s.face == DIRCT_LEFT)
		data->sprt.img = set_img(data, SPRITE_WALK_LEFT2_PATH);
	else if (s.face == DIRCT_RIGHT && s.x % 32 < 16)
		data->sprt.img = set_img(data, SPRITE_WALK_RIGHT1_PATH);
	else if (s.face == DIRCT_RIGHT)
		data->sprt.img = set_img(data, SPRITE_WALK_RIGHT2_PATH);
	else if (s.face == DIRCT_UP && s.y % 32 < 16)
		data->sprt.img = set_img(data, SPRITE_WALK_UP1_PATH);
	else if (s.face == DIRCT_UP)
		data->sprt.img = set_img(data, SPRITE_WALK_UP2_PATH);
	else if (s.face == DIRCT_DOWN && s.y % 32 < 16)
		data->sprt.img = set_img(data, SPRITE_WALK_DOWN1_PATH);
	else if (s.face == DIRCT_DOWN)
		data->sprt.img = set_img(data, SPRITE_WALK_DOWN2_PATH);
}

void	sprt_collect(t_data *data)
{
	data->sprt.img = set_img(data, SPRITE_KNEEL_PATH);
	data->sprt.animating += 1;
	if (data->sprt.animating == 30)
	{
		data->sprt.act = ACT_STAND;
		data->sprt.animating = 0;
	}
}

void	sprt_moving(t_data *data)
{
	t_sprt	s;

	s = data->sprt;
	if (s.x == s.nx && s.y == s.ny)
		sprt_standing(data);
	if (data->sprt.act != ACT_WALK)
		return ;
	if (s.face == DIRCT_LEFT)
		data->sprt.x -= 2;
	if (s.face == DIRCT_RIGHT)
		data->sprt.x += 2;
	if (s.face == DIRCT_UP)
		data->sprt.y -= 2;
	if (s.face == DIRCT_DOWN)
		data->sprt.y += 2;
}
