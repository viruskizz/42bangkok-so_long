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
static int	rkeyhandler(int keycode, t_data *data);
static int	mlx_close(int keycode, t_data *data);
static void	initial(t_data *data, char *filename);

// int	main(void)
int	main(int argc, char **argv)
{
	t_data	data;
	char	*filename;

	if (argc == 1)
		filename = MAP_FILE;
	else
		filename = argv[1];
	initial(&data, filename);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 1L << 0, &keyhandler, &data);
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 1L << 0, &mlx_close, &data);
	mlx_loop(data.mlx);
	return (0);
}

static void	initial(t_data *data, char *filename)
{
	data->mlx = mlx_init();
	data->frame = 0;
	data->stime = 0;
	if (!data->mlx)
		error_game(data, ERROR_MLX, NULL);
	load_file(data, filename);
	load_map(data);
	load_tiles(data);
	data->win = mlx_new_window(data->mlx, data->w, data->h, "SO LONG");
	if (!data->win)
		error_game(data, ERROR_WIN, NULL);
	load_game(data);
}

static int	mlx_close(int keycode, t_data *data)
{
	ft_printf("Close Game\n");
	exit(0);
	return (0);
}

static int	render(t_data *data)
{
	if (data->frame == FRAME_RATE)
	{
		data->frame = 0;
		data->stime += 1;
	}
	else
		data->frame += 1;
	render_sprts_util(data, data->bg);
	render_sprts_util(data, data->panel.bg);
	render_sprts_util(data, data->panel.score);
	render_sprts_util(data, data->objs);
	render_sprts_fnc_util(data, data->enemies, &move_enemies);
	render_player(data);
	chk_pos_player(data);
	return (0);
}

static int	keyhandler(int keycode, t_data *data)
{
	int	m;

	ft_printf("key: %d\n", keycode);
	m = TILE_SIZE;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		moving_handling(data, DIRCT_LEFT, m * -1, 0);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		moving_handling(data, DIRCT_RIGHT, m, 0);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		moving_handling(data, DIRCT_DOWN, 0, m);
	if (keycode == KEY_UP || keycode == KEY_W)
		moving_handling(data, DIRCT_UP, 0, m * -1);
	if (keycode == KEY_SPACE)
		space_handling(data);
	if (keycode == KEY_ESC)
		exit_game(data, EXIT_SUCCEED);
	return (0);
}
