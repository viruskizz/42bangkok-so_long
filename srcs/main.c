/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:28:30 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 01:28:31 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render(t_data *data);
static int	keyhandler(int keycode, t_data *data);
static int	mlx_close(int keycode, t_data *data);
static int	initial(t_data *data, char *filename);

int	main(void)
{
	t_data	data;

	if (!initial(&data, MAP_FILE))
		error_game(&data, ERROR_MLX);
	// render_background(&data);
	// render_map(&data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 1L << 0, &keyhandler, &data);
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 1L << 0, &mlx_close, &data);
	mlx_loop(data.mlx);
	// free(data.win);
	// free(data.mlx);
	return (0);
}

static int	initial(t_data *data, char *filename)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_game(data, ERROR_MLX);
	load_file(data, MAP_FILE);
	load_map(data);
	data->win = mlx_new_window(
			data->mlx, data->map.width, data->map.height, "SO LONG");
	if (!data->win)
		error_game(data, ERROR_WIN);
	load_background(data);
	load_sprites(data);
	load_objects(data);
	return (1);
}

static int	mlx_close(int keycode, t_data *data)
{
	exit_game(data, EXIT_SUCCEED);
	return (0);
}

static int	render(t_data *data)
{
	render_background(data);
	render_map(data);
	render_object(data);
	render_sprite(data);
	// if (data->render)
	// {
	// 		ft_printf("Render");
	// 		render_background(data);
	// 		render_map(data);
	// 		render_object(data);
	//		render_sprite(data);
	// 		data->render = 0;
	// }
	return (0);
}

static int	keyhandler(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move_sprite(data, SPIRIT_SIZE * -1, 0);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_sprite(data, SPIRIT_SIZE, 0);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move_sprite(data, 0, SPIRIT_SIZE);
	if (keycode == KEY_UP || keycode == KEY_W)
		move_sprite(data, 0, SPIRIT_SIZE * -1);
	if (keycode == KEY_SPACE)
		collect_object(data);
	if (keycode == KEY_ESC)
		exit_game(data, EXIT_SUCCEED);
	return (0);
}
