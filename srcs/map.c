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

static t_tile	new_tile(t_data *data, char type, int x, int y)
{
	t_tile	tile;
	t_img	img;

	tile.type = type;
	tile.x = x;
	tile.y = y;
	if (type == '1')
		img.mlx = mlx_xpm_file_to_image(
				data->mlx, OBJECT_WALL_PATH, &img.w, &img.h);
	else if (type == 'E')
		img.mlx = mlx_xpm_file_to_image(
				data->mlx, OBJECT_EXIT_PATH, &img.w, &img.h);
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
	data->map.items = 0;
	while (*str)
	{
		j = 0;
		data->map.tiles[i] = malloc(sizeof(t_tile) * data->map.tile_x);
		while (*str != '\n' && *str)
		{
			data->map.tiles[i][j] = new_tile(
					data, *str, j * TILE_SIZE, i * TILE_SIZE);
			if (*str == 'C')
				data->map.items++;
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

t_tile	get_tile(t_data *data, int x, int y)
{
	return (data->map.tiles[y / SPIRIT_SIZE][x / TILE_SIZE]);
}
