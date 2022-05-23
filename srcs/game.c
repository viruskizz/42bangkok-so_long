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

void	exit_game(t_data *data)
{
	printf("OS: %s\n", OS);
	free(data->map.filedata);
	// mlx_destroy_image(data->mlx_ptr, data->background.mlx_img);
	// mlx_destroy_image(data->mlx_ptr, data->objects.walls.mlx_img);
	// mlx_destroy_image(data->mlx_ptr, data->sprite.mlx_img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	// if (IS_LINUX)
	// {
	// 	mlx_destroy_display(data->mlx_ptr); // ONLY Linux
	// 	free(data->mlx_ptr); // Free ONLY Linux
	// }
	exit(0);
}
