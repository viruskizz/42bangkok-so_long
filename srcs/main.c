#include "so_long.h"
#include "libft.h"
#include <stdio.h>

int	mlx_close (int keycode, t_data *data)
{
	(void) *data;
	printf("CLOSE: %d\n", keycode);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	exit(0);
}

int	initial(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	// mlx_pixel_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, 0xFFFFFF);
	data->background.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->background.addr = mlx_get_data_addr(data->background.mlx_img, &data->background.bpp, &data->background.line_len, &data->background.endian);
	render_background(&data->background, WHITE_PIXEL);
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, SPIRIT_SIZE, SPIRIT_SIZE, GREEN_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.mlx_img, 0, 0);
	return (0);
}

int	render(t_data *data)
{
	printf("render %d\n", data->redraw); fflush(stdout);
	initial(data);
	t_img	img = data->sprite;
	img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "images/sprites/squall.xpm", &img.width, &img.height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, img.x, img.y);
	if (data->redraw)
	{

		data->redraw = 0;
	}
	return (0);
}

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

	data.sprite.x = 50;
	data.sprite.y = 50;
	data.redraw = 1;
	// img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "images/sprites/squall.xpm", &img.width, &img.height);
	// img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	/* Setup hooks */
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, X_EVENT_KEY_PRESS, 1L << 0, &keyhandler, &data);
	mlx_hook(data.win_ptr, X_EVENT_KEY_EXIT, 1L << 0, &mlx_close, &data);
	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	// mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
