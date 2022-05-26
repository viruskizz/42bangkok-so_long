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

void	move_sprite(t_data *data, int dirct, int dx, int dy)
{
	t_tile	nt;

	if (data->sprt.act != ACT_STAND)
		return ;
	data->sprt.act = ACT_WALK;
	data->sprt.face = dirct;
	nt = get_tile(data, data->sprt.x + dx, data->sprt.y + dy);
	if (nt.type == '1')
		return ;
	data->sprt.nx = data->sprt.x + dx;
	data->sprt.ny = data->sprt.y + dy;
	data->sprt.moved++;
	ft_printf("MOVED: %d\n", data->sprt.moved);
	chk_pos_sprite(data);
}

void	sit_sprite(t_data *data)
{
	t_tile	t;

	t = get_tile(data, data->sprt.x, data->sprt.y);
	if (data->sprt.act == ACT_STAND)
		data->sprt.act = ACT_SIT;
	else if (data->sprt.act == ACT_SIT)
		data->sprt.act = ACT_STAND;
	if (t.type == 'C')
		collect_object(data, t);
}

static void	collect_object(t_data *data, t_tile t)
{
	t_tile	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->x == t.x && obj->y == t.y)
		{
			if (obj->img.mlx)
			{
				mlx_destroy_image(data->mlx, obj->img.mlx);
				obj->img.mlx = NULL;
				data->sprt.act = ACT_COLLECTED;
				data->sprt.item++;
			}
			return ;
		}
		obj = obj->next;
	}
}
