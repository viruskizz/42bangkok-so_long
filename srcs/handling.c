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

	if (data->player.act != ACT_STAND)
		return ;
	data->player.act = ACT_WALK;
	data->player.face = dirct;
	nt = get_tile(data, data->player.v.x + dx, data->player.v.y + dy);
	if (nt.type == '1')
		return ;
	data->player.nv.x = data->player.v.x + dx;
	data->player.nv.y = data->player.v.y + dy;
	data->player.moved++;
	ft_printf("MOVED: %d\n", data->player.moved);
}

void	space_handling(t_data *data)
{
	t_tile	t;

	t = get_tile(data, data->player.v.x, data->player.v.y);
	if (data->player.act == ACT_STAND)
		data->player.act = ACT_SIT;
	else if (data->player.act == ACT_SIT)
		data->player.act = ACT_STAND;
	if (t.type == 'C')
		collect_object(data, t);
}

static void	collect_object(t_data *data, t_tile t)
{
	t_tile	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->v.x == t.v.x && obj->v.y == t.v.y)
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
