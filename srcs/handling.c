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

static void	collect_object(t_data *data, t_tile t);

void	moving_handling(t_data *data, int dirct, int dx, int dy)
{
	t_tile	nt;
	t_vtr	nv;

	if (data->player.act != ACT_STAND)
		return ;
	data->player.act = ACT_WALK;
	data->player.face = dirct;
	nv.x = data->player.v.x + dx;
	nv.y = data->player.v.y + dy;
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
		collect_object(data, t);
}

static void	collect_object(t_data *data, t_tile t)
{
	t_sprt	*obj;
	t_sprt	p;

	obj = data->objs;
	while (obj)
	{
		if (obj->v.x == t.v.x && obj->v.y == t.v.y && t.type == 'C')
		{
			if (obj->img.mlx)
			{
				mlx_destroy_image(data->mlx, obj->img.mlx);
				obj->img.mlx = NULL;
				data->player.act = ACT_COLLECTED;
				data->player.item++;
			}
			return ;
		}
		obj = obj->next;
	}
}
