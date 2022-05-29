/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:48:35 by araiva            #+#    #+#             */
/*   Updated: 2022/05/29 23:48:37 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_switch_acting(t_data *data)
{
	t_sprt	p;

	p = data->player;
	mlx_destroy_image(data->mlx, p.img.mlx);
	if (p.act == ACT_FALLEN)
		data->player.img = set_img(data, SPRITE_FALLEN_PATH);
	else if (p.act == ACT_SLEEP)
		data->player.img = set_img(data, SPRITE_SLEEP_PATH);
	else if (p.act == ACT_SIT)
		data->player.img = set_img(data, SPRITE_KNEEL_PATH);
}

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
