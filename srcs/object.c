/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:33:15 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:33:16 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_tile	*new_obj(t_data *data, int x, int y)
{
	t_tile	*obj;

	obj = malloc(sizeof(t_tile));
	obj->type = 'C';
	obj->v.x = x;
	obj->v.y = y;
	obj->img = set_img(data, OBJECT_ITEM_PATH);
	obj->next = NULL;
	return (obj);
}

void	load_objects(t_data *data)
{
	int		gx;
	int		gy;
	t_tile	*obj;
	t_tile	*tmp;

	gy = 0;
	data->objs = NULL;
	while (gy < data->map.grid_y)
	{
		gx = 0;
		while (gx < data->map.grid_x)
		{
			if (data->map.tiles[gy][gx].type == 'C')
			{
				obj = new_obj(data, gx * TILE_SIZE, gy * TILE_SIZE);
				if (data->objs)
					tmp->next = obj;
				else
					data->objs = obj;
				tmp = obj;
			}
			gx++;
		}
		gy++;
	}
}

void	render_objects(t_data *data)
{
	t_tile	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, obj->img.mlx, obj->v.x, obj->v.y);
		obj = obj->next;
	}
}

void	free_objects(t_data *data)
{
	t_tile	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->img.mlx)
			mlx_destroy_image(data->mlx, obj->img.mlx);
		obj = obj->next;
	}
}
