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
	data->bg = NULL;
	data->enemies = NULL;
	grid_loop_util(data, &new_bg);
	load_panel(data);
	load_score(data);
	grid_loop_util(data, &new_obj);
	grid_loop_util(data, &initial_player);
	grid_loop_util(data, &new_enemy);
}

void	exit_game(t_data *data, int code)
{
	ft_printf("Exit Game\n");
	free_sprts_util(data, data->bg);
	free_sprts_util(data, data->objs);
	free_sprts_util(data, data->panel.bg);
	free_sprts_util(data, data->panel.score);
	free_sprts_util(data, data->enemies);
	if (data->map.filedata)
		free(data->map.filedata);
	if (data->mlx)
		free(data->mlx);
	if (data->win)
		free(data->win);
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
