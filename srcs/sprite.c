#include "so_long.h"

void	load_sprites(t_data *data)
{
	int		size;

	size = SPIRIT_SIZE / 2;
	data->sprite.x = 50;
	data->sprite.y = 50;
	data->sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_SQUALL_PATH, &size, &size);
}

void	render_sprite(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.mlx_img, data->sprite.x, data->sprite.y);
}