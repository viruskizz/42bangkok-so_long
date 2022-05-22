#include "so_long.h"

void	exit_game(t_data *data)
{
	printf("OS: %s\n", OS);
	mlx_destroy_image(data->mlx_ptr, data->background.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->objects.wall.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprite.mlx_img);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// if (IS_LINUX)
	// {
	// 	mlx_destroy_display(data->mlx_ptr); // ONLY Linux
	// 	free(data->mlx_ptr); // Free ONLY Linux
	// }
}