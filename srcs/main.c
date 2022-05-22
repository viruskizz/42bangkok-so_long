#include "so_long.h"
#include "libft.h"
#include <stdio.h>

int	render(t_data *data);
int keyhandler(int keycode, t_data *data);
int	mlx_close (int keycode, t_data *data);


int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "SO LONG");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	load_sprites(&data);
	load_objects(&data);
	/* Setup hooks */
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, X_EVENT_KEY_PRESS, 1L << 0, &keyhandler, &data);
	mlx_hook(data.win_ptr, X_EVENT_KEY_EXIT, 1L << 0, &mlx_close, &data);
	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	// free(data.mlx_ptr);
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	return (0);
}

int	mlx_close (int keycode, t_data *data)
{
	printf("CLOSE: %d\n", keycode);
	(void) data;
	// mlx_destroy_image(data->mlx_ptr, data->background.mlx_img);
	// mlx_destroy_image(data->mlx_ptr, data->objects.wall.mlx_img);
	// mlx_destroy_image(data->mlx_ptr, data->sprite.mlx_img);
	// mlx_clear_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_display(data->mlx_ptr); // ONLY Linux
	// free(data->mlx_ptr); // Free ONLY Linux
	exit(0);
	return (0);
}

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	render_background(data);
	render_sprite(data);
	render_object(data);
	return (0);
}


int keyhandler(int keycode, t_data *data)
{
	printf("key: %d", keycode);
	int	move_size;

	move_size = SPIRIT_SIZE / 8;
	if (keycode == KEY_A)
		data->sprite.x -= move_size;
	if (keycode == KEY_D)
		data->sprite.x += move_size;
	if (keycode == KEY_S)
		data->sprite.y += move_size;
	if (keycode == KEY_W)
		data->sprite.y -= move_size;
	fflush(stdout);
	return (0);
}
