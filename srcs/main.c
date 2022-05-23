#include "so_long.h"

static int	render(t_data *data);
static int	keyhandler(int keycode, t_data *data);
static int	mlx_close (int keycode, t_data *data);
static int	initial(t_data *data);

int	main(void)
{
	t_data	data;

	if (initial(&data) == MLX_ERROR)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
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

static int	initial(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MLX_ERROR);
	read_file(data, "maps/simple.ber");
	load_map(data);
	data->win = mlx_new_window(data->mlx, data->map.width, data->map.height, "SO LONG");
	if (!data->win)
	{
		free(data->win);
		free(data->map.filedata);
		return (MLX_ERROR);
	}
	set_background(data);
	load_sprites(data);
	load_objects(data);
	return (0);
}

static int	mlx_close (int keycode, t_data *data)
{
	(void) data;
	exit(0);
	return (0);
}

static int	render(t_data *data)
{
	if (!data->win)
		return (1);
	render_background(data);
	render_map(data);
	render_object(data);
	render_sprite(data);
	return (0);
}


static int keyhandler(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move_sprite(data, SPIRIT_SIZE * -1, 0);
	if (keycode ==  KEY_RIGHT || keycode == KEY_D)
		move_sprite(data, SPIRIT_SIZE, 0);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move_sprite(data, 0, SPIRIT_SIZE);
	if (keycode == KEY_UP || keycode == KEY_W)
		move_sprite(data, 0, SPIRIT_SIZE * -1);
	if (keycode == KEY_SPACE)
		collect_object(data);
	if (keycode == KEY_ESC)
		exit_game(data);
	return (0);
}
