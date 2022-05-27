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
	return (data->map.tiles[y / SPIRIT_SIZE][x / TILE_SIZE]);
}

int	is_ovelap_tile(t_vtr v1, t_vtr v2)
{
	int	ts;

	ts = TILE_SIZE;
	if ((v1.x < v2.x && v2.x < v1.x + ts) &&
			(v1.y < v2.y && v2.y < v1.y + ts))
		return (1);
	else
		return (0);
}
