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

t_tile	get_tile(t_data *data, int x, int y)
{
	int gx;
	int gy;

	gx = x / SPIRIT_SIZE;
	gy = y / SPIRIT_SIZE;
	return (data->map.tiles[gy][gx]);
}

int	is_ovelap_tile(t_vtr v1, t_vtr v2, t_vtr o1, t_vtr o2)
{
	int	ts;

	ts = TILE_SIZE;
	if (v1.x == v2.x && v1.y == v2.y)
		return (1);
	// ft_printf("%d,%d = %d,%d", v1.x, v1.y, v2.x, v2.y);
	if (v1.x > v2.x + ts || v1.x + ts < v2.x ||
		v1.y < v2.y + ts || v1.y + ts < v2.y)
		return (0);
	else
		return (1);
}
