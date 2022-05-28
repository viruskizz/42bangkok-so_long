/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:43:10 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:43:11 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map_data(t_data *data, int is_init);

static t_tile	new_tile(t_data *data, char type, int x, int y)
{
	t_tile	tile;
	t_img	img;

	tile.type = type;
	tile.v.x = x;
	tile.v.y = y;
	return (tile);
}

void	load_map(t_data *data)
{
	char	*f;

	f = data->map.filedata;
	init_map_data(data, 1);
	while (*f)
	{
		while (*f && *f != '\n')
		{
			if (data->map.grid_y == 0)
				data->map.grid_x++;
			if (*f == 'C')
				data->map.item++;
			else if (*f == 'E')
				data->map.exit++;
			else if (*f == 'P')
				data->map.player++;
			else if (*f == 'M')
				data->map.enemy++;
			f++;
		}
		data->map.grid_y++;
		f++;
	}
	init_map_data(data, 0);
	validate_map(data);
}

void	load_tiles(t_data *data)
{
	char	*str;
	int		gx;
	int		gy;

	data->map.tiles = malloc(sizeof(t_tile *) * data->map.grid_y);
	gy = 0;
	str = data->map.filedata;
	while (*str)
	{
		gx = 0;
		data->map.tiles[gy] = malloc(sizeof(t_tile) * data->map.grid_x);
		while (*str != '\n' && *str)
		{
			data->map.tiles[gy][gx] = new_tile(
					data, *str, gx * TILE_SIZE, gy * TILE_SIZE);
			gx++;
			str++;
		}
		str++;
		gy++;
	}
}

static void	init_map_data(t_data *data, int is_init)
{
	if (is_init)
	{
		data->map.grid_x = 0;
		data->map.grid_y = 0;
		data->map.item = 0;
		data->map.exit = 0;
		data->map.player = 0;
		data->map.boss = 1;
		data->map.enemy = 1;
	}
	else
	{
		data->map.width = data->map.grid_x * TILE_SIZE;
		data->map.height = data->map.grid_y * TILE_SIZE;
		data->w = data->map.width;
		data->h = data->map.height + TILE_SIZE;
	}
}
