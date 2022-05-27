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
	tile.x = x;
	tile.y = y;
	if (type == '1')
		img = set_img(data, OBJECT_WALL_PATH);
	else if (type == 'E')
		img = set_img(data, OBJECT_EXIT_PATH);
	else
		img.mlx = NULL;
	tile.img = img;
	return (tile);
}

void	load_map(t_data *data)
{
	char	*str;
	int		i;
	int		j;

	data->map.tiles = malloc(sizeof(t_tile *) * data->map.tile_y);
	i = 0;
	str = data->map.filedata;
	while (*str)
	{
		j = 0;
		data->map.tiles[i] = malloc(sizeof(t_tile) * data->map.tile_x);
		while (*str != '\n' && *str)
		{
			data->map.tiles[i][j] = new_tile(
					data, *str, j * TILE_SIZE, i * TILE_SIZE);
			j++;
			str++;
		}
		str++;
		i++;
	}
}

void	render_map(t_data *data)
{
	int		i;
	int		j;
	t_tile	t;

	i = 0;
	while (i < data->map.tile_y)
	{
		j = 0;
		while (j < data->map.tile_x)
		{
			t = data->map.tiles[i][j];
			if (t.img.mlx)
				mlx_put_image_to_window(
					data->mlx, data->win, t.img.mlx, t.x, t.y);
			j++;
		}
		i++;
	}
}

void	validate_map(t_data *data)
{
	t_map	m;

	m = data->map;
	if (m.tile_x * m.tile_y < 4 * 4)
		error_game(data, ERROR_MAP_INVALID, "map is small.");
	if (ft_strlen(m.filedata) != m.tile_x * m.tile_y + m.tile_y - 1)
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
			if ((x == 0 || x == map.tile_x - 1) && f[i] != '1')
				return (0);
			if ((y == 0 || y == map.tile_y -1) && f[i] != '1')
				return (0);
			i++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}
