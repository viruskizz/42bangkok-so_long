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

static int	valid_wall(t_map map);

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

void	validate_map(t_data *data)
{
	t_map	m;

	m = data->map;
	if (m.grid_x * m.grid_y < 4 * 4)
		error_game(data, ERROR_MAP_INVALID, "map is small.");
	if (ft_strlen(m.filedata) != m.grid_x * m.grid_y + m.grid_y - 1)
		error_game(data, ERROR_MAP_INVALID, "map is not rect.");
	if (m.item == 0 || m.player == 0 || m.exit != 1)
		error_game(data, ERROR_MAP_INVALID, "map not meet minimun requirement");
	if (valid_wall(data->map) == 0)
		error_game(data, ERROR_MAP_INVALID, "map not covered with wall.");
}

static int	valid_wall(t_map map)
{
	int		i;
	int		x;
	int		y;
	char	*f;

	i = 0;
	x = 0;
	y = 0;
	f = map.filedata;
	while (f[i])
	{
		x = 0;
		while (f[i] && f[i] != '\n')
		{
			if ((x == 0 || x == map.grid_x - 1) && f[i] != '1')
				return (0);
			if ((y == 0 || y == map.grid_y -1) && f[i] != '1')
				return (0);
			i++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}
