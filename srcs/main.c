#include "so_long.h"
#include "libft.h"
#include <stdio.h>
/*
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}
*/

// int	render_rect(t_data *data, t_rect rect)
// {
// 	int	i;
// 	int	j;

// 	if (!data->win_ptr)
// 		return (1);
// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
// 		++i;
// 	}
// 	return (0);
// }

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, 0xFF0000);
	render_background(data, WHITE_PIXEL);
	render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
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
	/* Setup hooks */
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	// mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx_ptr);
	return (0);
}
