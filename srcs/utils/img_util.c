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

t_tile	*new_bg(t_data *data, int x, int y)
{
	t_tile	*t;

	t = malloc(sizeof(t_tile));
	if (!t)
		exit(1);
	t->x = x;
	t->y = y;
	t->type = '0';
	t->img.mlx = mlx_xpm_file_to_image(
			data->mlx, OBJECT_GRASS_PATH, &t->img.w, &t->img.h);
	t->next = NULL;
	return (t);
}

void	load_background(t_data *data)
{
	int		x;
	int		y;
	t_tile	*bg;
	t_tile	*tmp;

	x = 0;
	y = 0;
	data->bg = NULL;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			bg = new_bg(data, x, y);
			if (data->bg)
				tmp->next = bg;
			else
				data->bg = bg;
			tmp = bg;
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

void	render_background(t_data *data)
{
	t_tile	*bg;

	bg = data->bg;
	while (bg)
	{
		if (bg->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, bg->img.mlx, bg->x, bg->y);
		bg = bg->next;
	}
}

// void	free_background(t_data *data)
// {

// }

t_img	set_img(t_data *data, char *path)
{
	t_img img;

	img.mlx = mlx_xpm_file_to_image(data->mlx, path, &img.w, &img.h);
	return (img);
}
