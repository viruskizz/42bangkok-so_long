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
	mlx_destroy_image(data->mlx, p.img.mlx);
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
	int		r;

	p = data->player;
	r = data->bsize / 2;
	mlx_destroy_image(data->mlx, p.img.mlx);
	if (p.face == DIRCT_LEFT && p.v.x % r < r / 2)
		data->player.img = set_img(data, SPRITE_WALK_LEFT1_PATH);
	else if (p.face == DIRCT_LEFT)
		data->player.img = set_img(data, SPRITE_WALK_LEFT2_PATH);
	else if (p.face == DIRCT_RIGHT && p.v.x % r < r / 2)
		data->player.img = set_img(data, SPRITE_WALK_RIGHT1_PATH);
	else if (p.face == DIRCT_RIGHT)
		data->player.img = set_img(data, SPRITE_WALK_RIGHT2_PATH);
	else if (p.face == DIRCT_UP && p.v.y % r < r / 2)
		data->player.img = set_img(data, SPRITE_WALK_UP1_PATH);
	else if (p.face == DIRCT_UP)
		data->player.img = set_img(data, SPRITE_WALK_UP2_PATH);
	else if (p.face == DIRCT_DOWN && p.v.y % r < r / 2)
		data->player.img = set_img(data, SPRITE_WALK_DOWN1_PATH);
	else if (p.face == DIRCT_DOWN)
		data->player.img = set_img(data, SPRITE_WALK_DOWN2_PATH);
}

void	player_collect(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.img.mlx);
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
	t_vtr	mv;

	p = data->player;
	if (p.v.x == p.nv.x && p.v.y == p.nv.y)
		player_standing(data);
	if (data->player.act != ACT_WALK)
		return ;
	mv = get_move_vtr(p.face, 1);
	data->player.v = add_vtr(data->player.v, mv);
}

void	player_hurting(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.img.mlx);
	data->player.img = set_img(data, SPRITE_HURT_PATH);
	data->player.act = ACT_HURTING;
	data->player.animating += 1;
	if (data->player.animating == FRAME_RATE / 2)
	{
		data->player.act = ACT_FALLEN;
		data->player.animating = 0;
	}
}

void	player_sleeping(t_data *data)
{
	t_sprt	p;

	p = data->player;
	if (p.act != ACT_STAND)
		return ;
	mlx_destroy_image(data->mlx, data->player.img.mlx);
	data->player.act = ACT_SLEEP;
	data->player.img = set_img(data, SPRITE_SLEEP_PATH);
}

void	player_interacting(t_data *data)
{
	t_sprt	p;
	t_tile	t;

	p = data->player;
	mlx_destroy_image(data->mlx, data->player.img.mlx);
	data->player.act = ACT_INTERACT;
	data->player.img = set_img(data, SPRITE_INTERACT_PATH);
	data->player.animating += 1;
	if (data->player.animating == FRAME_RATE / 2)
	{
		data->player.act = ACT_STAND;
		data->player.animating = 0;
		t = get_tile(data, data->player.v);
		p = data->player;
		if (t.type == 'E')
		{
			if (data->map.item == p.item)
				exit_game(data, EXIT_SUCCEED);
		}
	}
}
