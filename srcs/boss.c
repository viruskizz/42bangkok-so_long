/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:58:56 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/28 22:58:57 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sprt	initial_boss(t_data *data, int gx, int gy)
{
	t_sprt b;

	b.v.x = gx * TILE_SIZE;
	b.v.y = gy * TILE_SIZE;
	b.nv.x = b.v.x;
	b.nv.y = b.v.y;
	b.animating = 0;
	b.act = ACT_STAND;
	b.face = DIRCT_DOWN;
	b.img = set_img(data, BOSS_PATH);
	return (b);
}

void	load_boss(t_data *data)
{
	int	gx;
	int	gy;

	data->boss = initial_boss(data, 2, 2);
}

void	render_boss(t_data *data)
{
	t_sprt b;

	b = data->boss;
	if (b.img.mlx)
		mlx_put_image_to_window(data->mlx, data->win, b.img.mlx, b.v.x, b.v.y);
}
