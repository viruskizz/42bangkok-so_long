/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:57:25 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:57:27 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	set_bg(t_data *data, int x, int y)
{
	t_tile	t;

	t.x = x;
	t.y = y;
	t.type = '0';
	t.img.mlx = mlx_xpm_file_to_image(
			data->mlx, OBJECT_GRASS_PATH, &t.img.w, &t.img.h);
	return (t);
}

void	set_background(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	data->bg = malloc(sizeof(t_tile) * data->map.tile_x * data->map.tile_y);
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			data->bg[i] = set_bg(data, x, y);
			x += TILE_SIZE;
			i++;
		}
		y += TILE_SIZE;
	}
}

void	render_background(t_data *data)
{
	int		i;
	t_tile	bg;

	i = 0;
	while (i < data->map.tile_x * data->map.tile_y)
	{
		bg = data->bg[i];
		if (bg.img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, bg.img.mlx, bg.x, bg.y);
		i++;
	}
}

// void	free_background(t_data *data)
// {

// }
