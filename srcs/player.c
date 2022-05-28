/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:51:45 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:51:46 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initial_player(t_data *data, t_tile t)
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

void	load_player(t_data *data)
{
	grid_loop_util(data, &initial_player);
}

void	render_player(t_data *data)
{
	t_sprt	p;

	p = data->player;
	if (p.act == ACT_FALLEN)
		data->player.img = set_img(data, SPRITE_FALLEN_PATH);
	else if (p.act == ACT_HURTING)
		player_hurting(data);
	else if (p.act == ACT_WALK)
	{
		player_moving(data);
		player_walking(data);
	}
	else if (p.act == ACT_SIT)
		data->player.img = set_img(data, SPRITE_KNEEL_PATH);
	else if (p.act == ACT_STAND)
		player_standing(data);
	else if (p.act == ACT_COLLECTED)
		player_collect(data);
	mlx_put_image_to_window(
		data->mlx, data->win, data->player.img.mlx, data->player.v.x, data->player.v.y);
}
