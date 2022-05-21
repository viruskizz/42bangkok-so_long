#include <stdio.h>
#include "mlx.h"
#include "so_long.h"

int key_handler(int keycode, t_data *data)
{
	(void) *data;
	printf("key: %d", keycode);
	int	move_size;

	move_size = SPIRIT_SIZE / 2;
	if (keycode == KEY_A)
		render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, SPIRIT_SIZE, SPIRIT_SIZE, GREEN_PIXEL});
	else if (keycode == KEY_D)
		render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, SPIRIT_SIZE, SPIRIT_SIZE, GREEN_PIXEL});
	else if (keycode == KEY_W)
		render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, SPIRIT_SIZE, SPIRIT_SIZE, GREEN_PIXEL});
	// if (keysym == )
	else if (keycode == KEY_S)
		render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, SPIRIT_SIZE, SPIRIT_SIZE, GREEN_PIXEL});
	// {
	// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// 	data->win_ptr = NULL;
	// }
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	fflush(stdout);
	return (0);
}
