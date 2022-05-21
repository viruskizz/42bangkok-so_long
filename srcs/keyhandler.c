#include <stdio.h>
#include "mlx.h"
#include "so_long.h"

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
	// 	render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2 + 10, WINDOW_HEIGHT / 2, SPIRIT_SIZE, SPIRIT_SIZE, GREEN_PIXEL});
	// else if (keycode == KEY_W)
	// 	render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 10, SPIRIT_SIZE, SPIRIT_SIZE, GREEN_PIXEL});
	// // if (keysym == )
	// else if (keycode == KEY_S)
	// 	render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 10, SPIRIT_SIZE, SPIRIT_SIZE, GREEN_PIXEL});
	// {
	// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// 	data->win_ptr = NULL;
	// }
	// mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	// render(data);
	fflush(stdout);
	return (0);
}
