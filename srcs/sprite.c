/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:51:45 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:51:46 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_data *data)
{
	int		i;
	int		j;
	t_sprt	s;

	i = 0;
	ft_printf("loading\n");
	while (i < data->map.tile_y)
	{
		j = 0;
		while (j < data->map.tile_x)
		{
			if (data->map.tiles[i][j].type == 'P')
			{
				ft_printf("%c: %d, %d\n", data->map.tiles[i][j].type, data->map.tiles[i][j].x, data->map.tiles[i][j].y);
				s.x = j * TILE_SIZE;
				s.y = i * TILE_SIZE;
				s.nx = s.x;
				s.ny = s.y;
				s.act = ACT_STAND;
				s.face = DIRCT_DOWN;
				s.item = 0;
				s.moved = 0;
				s.img.mlx = mlx_xpm_file_to_image(
						data->mlx, SPRITE_STAND_DOWN_PATH, &s.img.w, &s.img.h);
				data->sprt = s;
				printf("ACT: %d\n", data->sprt.act);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	render_sprite(t_data *data)
{
	t_sprt s;

	s = data->sprt;
	// printf("ACT: %d\n", data->sprt.act);
	// if (s.act == ACT_STAND)
	// 	data->sprt.img.mlx = mlx_xpm_file_to_image(
	// 		data->mlx, SPRITE_STAND_DOWN_PATH, &s.img.w, &s.img.h);
	if (data->sprt.act == ACT_WALK)
		walking_animate(data);
	mlx_put_image_to_window(
		data->mlx, data->win, data->sprt.img.mlx, data->sprt.x, data->sprt.y);
}

void	move_sprite(t_data *data, int dirct)
{
	t_tile	nt;
	int		nx;
	int		ny;

	nx = 0;
	ny = 0;
	if (data->sprt.act != ACT_STAND)
		return ;
	data->sprt.act = ACT_WALK;
	data->sprt.face = dirct;
	if (dirct == DIRCT_LEFT)
		nx -= 64;
	if (dirct == DIRCT_RIGHT)
		nx += 64;
	if (dirct == DIRCT_UP)
		ny -= 64;
	if (dirct == DIRCT_DOWN)
		ny += 64;
	nt = get_tile(data, data->sprt.x + nx, data->sprt.y + ny);
	if (nt.type == '1')
		return ;
	data->sprt.nx = data->sprt.x + nx;
	data->sprt.ny = data->sprt.y + ny;
	data->sprt.moved++;
	ft_printf("MOVED: %d\n", data->sprt.moved);
	chk_pos_sprite(data);
}

void	chk_pos_sprite(t_data *data)
{
	t_tile	t;

	t = get_tile(data, data->sprt.x, data->sprt.y);
	if (t.type == 'E')
	{
		if (data->map.item == data->sprt.item)
			exit_game(data, EXIT_SUCCEED);
	}
}

int		walking_animate(t_data *data)
{
	t_img	img;
	t_sprt s;

	s = data->sprt;
	// ft_printf("animate %d,%d -> %d,%d\n", s.x, s.y, s.nx, s.ny);
	if (s.x == s.nx && s.y == s.ny)
	{
		if (s.face == DIRCT_LEFT)
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_STAND_LEFT_PATH, &s.img.w, &s.img.h);
		if (s.face == DIRCT_RIGHT)
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_STAND_RIGHT_PATH, &s.img.w, &s.img.h);
		if (s.face == DIRCT_UP)
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_STAND_UP_PATH, &s.img.w, &s.img.h);
		if (s.face == DIRCT_DOWN)
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_STAND_DOWN_PATH, &s.img.w, &s.img.h);
		data->sprt.act = ACT_STAND;
	}
	if (data->sprt.act != ACT_WALK)
		return (0);
	if (s.face == DIRCT_LEFT)
	{
		data->sprt.x -= 2;
		if (s.x % 32 < 16)
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_WALK_LEFT1_PATH, &s.img.w, &s.img.h);
		else
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_WALK_LEFT2_PATH, &s.img.w, &s.img.h);
	}
	if (s.face == DIRCT_RIGHT)
	{
		data->sprt.x += 2;
		if (s.x % 32 < 16)
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_WALK_RIGHT1_PATH, &s.img.w, &s.img.h);
		else
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_WALK_RIGHT2_PATH, &s.img.w, &s.img.h);
	}
	if (s.face == DIRCT_UP)
	{
		data->sprt.y -= 2;
		if (s.y % 32 < 16)
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_WALK_UP1_PATH, &s.img.w, &s.img.h);
		else
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_WALK_UP2_PATH, &s.img.w, &s.img.h);
	}
	if (s.face == DIRCT_DOWN)
	{
		data->sprt.y += 2;
		if (s.y % 32 < 16)
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_WALK_DOWN1_PATH, &s.img.w, &s.img.h);
		else
			data->sprt.img.mlx =  mlx_xpm_file_to_image(data->mlx, SPRITE_WALK_DOWN2_PATH, &s.img.w, &s.img.h);
	}
	return (0);
}

