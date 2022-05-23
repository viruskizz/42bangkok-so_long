#include "so_long.h"

int	render(t_data *data);
int keyhandler(int keycode, t_data *data);
int	mlx_close (int keycode, t_data *data);


int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	read_file(&data, "maps/simple.ber");
	printf("%s\n", data.map.filedata);
	load_map(&data);
	data.win = mlx_new_window(data.mlx, data.map.width, data.map.height, "SO LONG");
	if (!data.win)
	{
		free(data.win);
		return (MLX_ERROR);
	}
	set_background(&data);
	render_background(&data);
	render_map(&data);
	load_sprites(&data);
	load_objects(&data);
	// load_objects(&data);
	/* Setup hooks */
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 1L << 0, &keyhandler, &data);
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 1L << 0, &mlx_close, &data);
	mlx_loop(data.mlx);

	/* we will exit the loop if there's no window left, and execute this code */
	free(data.win);
	free(data.mlx);
	return (0);
}

int	mlx_close (int keycode, t_data *data)
{
	printf("CLOSE: %d\n", keycode);
	(void) data;
	exit(0);
	return (0);
}

int	render(t_data *data)
{
	if (!data->win)
		return (1);
	// render_background(data);
	// render_map(data);
	render_object(data);
	render_sprite(data);
	return (0);
}


int keyhandler(int keycode, t_data *data)
{
	printf("key: %d", keycode);
	int	move_size;

	move_size = SPIRIT_SIZE;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		data->sprt.x -= move_size;
	if (keycode ==  KEY_RIGHT || keycode == KEY_D)
		data->sprt.x += move_size;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		data->sprt.y += move_size;
	if (keycode == KEY_UP || keycode == KEY_W)
		data->sprt.y -= move_size;
	if (keycode == KEY_ESC)
	{
		exit_game(data);
		exit(0);
		return (0);
	}
	fflush(stdout);
	return (0);
}
