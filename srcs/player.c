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

static t_sprt	initial_player(t_data *data, int gx, int gy)
{
	t_sprt	p;

	p.x = gx * TILE_SIZE;
	p.y = gy * TILE_SIZE;
	p.nx = p.x;
	p.ny = p.y;
	p.animating = 0;
	p.act = ACT_STAND;
	p.face = DIRCT_DOWN;
	p.item = 0;
	p.moved = 0;
	p.img = set_img(data, SPRITE_STAND_DOWN_PATH);
	return (p);
}

void	load_player(t_data *data)
{
	int		gx;
	int		gy;
	t_sprt	p;

	gy = 0;
	while (gy < data->map.grid_y)
	{
		gx = 0;
		while (gx < data->map.grid_x)
		{
			if (data->map.tiles[gy][gx].type == 'P')
			{
				data->player = initial_player(data, gx, gy);
				return ;
			}
			gx++;
		}
		gy++;
	}
}

void	render_player(t_data *data)
{
	t_sprt	p;

	p = data->player;
	if (p.act == ACT_WALK)
	{
		player_moving(data);
		player_walking(data);
	}
	if (p.act == ACT_SIT)
		data->player.img = set_img(data, SPRITE_KNEEL_PATH);
	if (p.act == ACT_STAND)
		player_standing(data);
	if (p.act == ACT_COLLECTED)
		player_collect(data);
	mlx_put_image_to_window(
		data->mlx, data->win, data->player.img.mlx, data->player.x, data->player.y);
}
