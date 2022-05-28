/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:59:11 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 22:59:13 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	chk_pos_player(t_data *data)
{
	t_tile	t;
	t_sprt	p;
	t_sprt	*e;

	p = data->player;
	t = get_tile(data, p.v);
	if (t.type == 'E')
	{
		ft_printf("This is exit\n");
		if (data->map.item == p.item)
			exit_game(data, EXIT_SUCCEED);
	}
	e = data->enemies;
	while (e)
	{
		if (is_ovelap_tile(e->v, p.v, 0, 0))
		{
			if (p.act != ACT_HURTING && p.act != ACT_FALLEN)
				player_hurting(data);
		}
		e = e->next;
	}
}
