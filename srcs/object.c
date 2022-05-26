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
	obj->x = x;
	obj->y = y;
	obj->img.mlx = mlx_xpm_file_to_image(
			data->mlx, OBJECT_ITEM_PATH, &obj->img.w, &obj->img.h);
	obj->next = NULL;
	return (obj);
}

void	load_objects(t_data *data)
{
	int		i;
	int		j;
	t_tile	*obj;
	t_tile	*tmp;

	i = 0;
	data->objs = NULL;
	while (i < data->map.tile_y)
	{
		j = 0;
		while (j < data->map.tile_x)
		{
			if (data->map.tiles[i][j].type == 'C')
			{
				obj = new_obj(data, j * TILE_SIZE, i * TILE_SIZE);
				if (data->objs)
					tmp->next = obj;
				else
					data->objs = obj;
				tmp = obj;
			}
			j++;
		}
		i++;
	}
}

void	render_object(t_data *data)
{
	t_tile	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, obj->img.mlx, obj->x, obj->y);
		obj = obj->next;
	}
}

void	collect_object(t_data *data)
{
	t_tile	t;
	t_tile	*obj;

	t = get_tile(data, data->sprt.x, data->sprt.y);
	// ft_printf("ACT: %d", data->sprt.act);
	if (data->sprt.act == ACT_STAND)
		data->sprt.act = ACT_SIT;
	else if (data->sprt.act == ACT_SIT)
		data->sprt.act = ACT_STAND;
	if (t.type == 'C')
	{
		obj = data->objs;
		while (obj)
		{
			if (obj->x == t.x && obj->y == t.y)
			{
				if (obj->img.mlx)
				{
					data->sprt.item++;
					obj->img.mlx = NULL;
					data->sprt.act = ACT_COLLECTED;
				}
				return ;
			}
			obj = obj->next;
		}
	}
	// ft_printf("ACT: %d", data->sprt.act);
}
