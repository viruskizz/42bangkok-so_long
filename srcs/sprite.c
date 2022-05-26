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

static t_sprt	initial_sprite(t_data *data, int gx, int gy)
{
	t_sprt	s;

	s.x = gx * TILE_SIZE;
	s.y = gy * TILE_SIZE;
	s.nx = s.x;
	s.ny = s.y;
	s.animating = 0;
	s.act = ACT_STAND;
	s.face = DIRCT_DOWN;
	s.item = 0;
	s.moved = 0;
	s.img = set_img(data, SPRITE_STAND_DOWN_PATH);
	return (s);
}

void	load_sprites(t_data *data)
{
	int		i;
	int		j;
	t_sprt	s;

	i = 0;
	while (i < data->map.tile_y)
	{
		j = 0;
		while (j < data->map.tile_x)
		{
			if (data->map.tiles[i][j].type == 'P')
			{
				data->sprt = initial_sprite(data, j, i);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	render_sprite(t_data *data)
{
	t_sprt	s;

	s = data->sprt;
	if (data->sprt.act == ACT_WALK)
	{
		sprt_moving(data);
		sprt_walking(data);
	}
	if (data->sprt.act == ACT_SIT)
		data->sprt.img = set_img(data, SPRITE_KNEEL_PATH);
	if (data->sprt.act == ACT_STAND)
		sprt_standing(data);
	if (data->sprt.act == ACT_COLLECTED)
		sprt_collect(data);
	mlx_put_image_to_window(
		data->mlx, data->win, data->sprt.img.mlx, data->sprt.x, data->sprt.y);
}
