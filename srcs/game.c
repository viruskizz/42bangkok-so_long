/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:46:10 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:46:12 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_game(t_data *data)
{
	data->objs = NULL;
	grid_loop_util(data, &new_obj);
}

void	exit_game(t_data *data, int code)
{
	ft_printf("Exit Game\n");
	free_backgrounds(data);
	// free_objects(data);
	free_sprts_util(data, data->objs);
	// mlx_destroy_image(data->mlx_ptr, data->background.mlx_img);
	// mlx_destroy_image(data->mlx_ptr, data->objects.walls.mlx_img);
	// mlx_destroy_image(data->mlx, data->sprt.img.mlx);
	// ft_printf("mlx: %p\n", data->mlx);
	// ft_printf("win: %p\n", data->win);
	if (data->mlx && data->win)
	{
		// mlx_destroy_window(data->mlx, data->win);
	}
	// if (data->map.filedata)
	// 	free(data->map.filedata);
	// if (data->mlx)
	// 	free(data->mlx);
	// if (data->win)
	// 	free(data->win);
	// if (IS_LINUX)
	// {
	// 	mlx_destroy_display(data->mlx_ptr); // ONLY Linux
	// 	free(data->mlx_ptr); // Free ONLY Linux
	// }
	exit(code);
}

void	error_game(t_data *data, int code, char *msg)
{

	if (code == ERROR_FILE_OPEN || code == ERROR_MAP_INVALID)
		ft_printf("Error: %s\n", msg);
	else if (code == ERROR_MLX)
	{
		ft_printf("Error: MLX lib cannot operation\n");
		free(data->mlx);
	}
	else if (code == ERROR_WIN)
	{
		ft_printf("Error: MLX WIN lib cannoot operation\n");
		free(data->mlx);
		free(data->win);
	}
	free(data->map.filedata);
	exit(1);
}

void	render_game(t_data *data)
{
	render_sprts_util(data, data->panel.bg);
	render_sprts_util(data, data->objs);
}

void	chk_pos_player(t_data *data)
{
	t_tile	t;
	t_sprt	p;
	t_sprt	*e;

	p = data->player;
	t = get_tile(data, p.v);
	if (t.type == 'E')
	{
		ft_printf("This is exit\n");
		if (data->map.item == p.item)
			exit_game(data, EXIT_SUCCEED);
	}
	e = data->enemies;
	while (e)
	{
		if (is_ovelap_tile(e->v, p.v, 0, 0))
		{
			if (p.act != ACT_HURTING && p.act != ACT_FALLEN)
				player_hurting(data);
		}
		e = e->next;
	}
}
