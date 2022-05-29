/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:48:43 by araiva            #+#    #+#             */
/*   Updated: 2022/05/29 23:48:44 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_collecting(t_data *data)
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
