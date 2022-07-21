/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:55:44 by araiva            #+#    #+#             */
/*   Updated: 2022/05/29 23:55:45 by araiva           ###   ########.fr       */
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
		{
			data->player.act = ACT_STAND;
		}
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

void	restart_handling(t_data *data)
{
	t_sprt	*objs;

	restart_player(data);
	objs = data->objs;
	while(objs)
	{
		ft_printf("%c: %d, %d\n", objs->type, objs->v.x, objs->v.y);
		if (objs->type == 'C' && objs->img.mlx)
		{
			mlx_destroy_image(data->mlx, objs->img.mlx);
			objs->img.mlx = NULL;
		}
		objs = objs->next;
	}
	objs = data->objs;
	while(objs)
	{
		ft_printf("%c: %d, %d\n", objs->type, objs->v.x, objs->v.y);
		if (objs->type == 'C')
		{
			objs->img = set_img(data, OBJECT_ITEM_PATH);
		}
		objs = objs->next;
	}
	// grid_loop_util(data, &new_obj);
}