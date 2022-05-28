/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:10:02 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 23:10:03 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	grid_loop_util(t_data *data, void (*f)(t_data*, t_tile))
{
	t_tile	t;
	int		gx;
	int		gy;

	gy = 0;
	while (gy < data->map.grid_y)
	{
		gx = 0;
		while (gx < data->map.grid_x)
		{
			t = data->map.tiles[gy][gx];
			f(data, t);
			gx++;
		}
		gy++;
	}
}

void	add_sprt_list(t_sprt *list, t_sprt *new)
{
	t_sprt	*tmp;

	if (!list)
		list = new;
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
