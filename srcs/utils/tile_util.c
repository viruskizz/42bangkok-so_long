/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:45:19 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/26 02:45:20 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	get_tile(t_data *data, t_vtr v)
{
	int	gx;
	int	gy;

	gx = v.x / data->bsize;
	gy = v.y / data->bsize;
	return (data->map.tiles[gy][gx]);
}

/**
 * Rect1 left of Rect 2:	v1.x + ts < v2.x
 * Rect1 Right of Rect2:	v1.x > v2.x + ts
 * Rect1 Top of Rect2:		v1.y + ts < v2.y
 * Rect1 Below of Rect2:	v1.y > v2.y + ts
 * @param v1 vector of Rect1
 * @param v2 vector of Rect2
 * @param o1 offset of Rect1
 * @param o2 offset of Rect2
 */
int	is_ovelap_tile(t_vtr v1, t_vtr v2, int o1, int o2)
{
	int	ts;
	int	w1;
	int	w2;

	ts = TILE_SIZE;
	if (o1 == 0)
		o1 = ts / 8;
	if (o2 == 0)
		o2 = ts / 8;
	w1 = ts - o1;
	w2 = ts - o2;
	if (v1.x == v2.x && v1.y == v2.y)
		return (1);
	if ((v1.x + w1) < (v2.x + o2) || (v1.x + o1) > (v2.x + w2))
		return (0);
	if ((v1.y + w1) < (v2.y + o2) || (v1.y + o1) > (v2.y + w2))
		return (0);
	return (1);
}

t_tile	random_free_tile(t_data *data, int r)
{
	t_tile	**tiles;
	t_tile	ft;
	int		gx;
	int		gy;

	tiles = data->map.tiles;
	gy = 0;
	while (gy < data->map.grid_y)
	{
		gx = 0;
		while (gx < data->map.grid_x)
		{
			if (tiles[gy][gx].type == '0')
			{
				ft = tiles[gy][gx];
				if (data->frame % 60 <= r)
					return (ft);
			}
			gx++;
		}
		gy++;
	}
	return (ft);
}
