/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:21:27 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/27 02:21:28 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moving_handling(t_data *data, int dirct)
{
	t_tile	nt;
	t_vtr	mv;
	t_vtr	nv;

	if (data->player.act != ACT_STAND)
		return ;
	data->player.act = ACT_WALK;
	data->player.face = dirct;
	mv = get_move_vtr(data->player.face, 0);
	nv = add_vtr(data->player.v, mv);
	nt = get_tile(data, nv);
	if (nt.type == '1')
		return ;
	data->player.nv = nv;
	data->player.moved++;
	ft_printf("MOVED: %d\n", data->player.moved);
	update_score(data);
}

void	space_handling(t_data *data)
{
	t_tile	t;
	t_sprt	p;

	p = data->player;
	t = get_tile(data, data->player.v);
	if (p.act == ACT_STAND)
		data->player.act = ACT_SIT;
	else if (p.act == ACT_SIT)
		data->player.act = ACT_STAND;
	if (t.type == 'C')
		check_object_player(data, t);
}

void	ctrl_handling(t_data *data, int is_release)
{
	if (is_release)
	{
		if (data->player.act == ACT_SLEEP)
			data->player.act = ACT_STAND;
	}
	else
	{
		if (data->player.act == ACT_STAND)
			data->player.act = ACT_SLEEP;
	}
}

void	enter_handling(t_data *data)
{
	if (data->player.act != ACT_STAND)
		return ;
	data->player.act = ACT_INTERACT;
}
