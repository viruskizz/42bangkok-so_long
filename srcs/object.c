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

static void	new_obj(t_data *data, t_tile t);

void	load_objects(t_data *data)
{
	data->objs = NULL;
	grid_loop_util(data, &new_obj);
}

void	render_objects(t_data *data)
{
	render_sprts_util(data, data->objs);
}

void	free_objects(t_data *data)
{
	free_sprts_util(data, data->objs);
}

static void	new_obj(t_data *data, t_tile t)
{
	t_sprt	*obj;

	if (t.type != '0')
	{
		obj = malloc(sizeof(t_sprt));
		obj->v = t.v;
		obj->type = t.type;
		if (t.type == 'C')
			obj->img = set_img(data, OBJECT_ITEM_PATH);
		else if (t.type == '1')
			obj->img = set_img(data, OBJECT_WALL_PATH);
		else if (t.type == 'E')
			obj->img = set_img(data, OBJECT_EXIT_PATH);
		obj->next = NULL;
		if (!data->objs)
			data->objs = obj;
		else
			add_sprt_list(data->objs, obj);
	}
}
