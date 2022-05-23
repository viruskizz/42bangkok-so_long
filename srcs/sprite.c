#include "so_long.h"

void	load_sprites(t_data *data)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < data->map.tile_y)
	{
		j = 0;
		while (j < data->map.tile_x)
		{
			if (data->map.tiles[i][j].type == 'P')
			{
				data->sprt.x = j * TILE_SIZE;
				data->sprt.y = i * TILE_SIZE;
				// data->sprt.img.addr = mlx_get_data_addr(data->sprt.img.mlx, &data->sprt.img.bpp, &data->sprt.img.line_len, &data->sprt.img.endian);
				data->sprt.img.mlx = mlx_xpm_file_to_image(data->mlx, SPRITE_SQUALL_PATH, &data->sprt.img.width, &data->sprt.img.height);
				return ;
			}
			j++;
		}	
		i++;
	}
}

void	render_sprite(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprt.img.mlx, data->sprt.x, data->sprt.y);
	if (data->redraw)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprt.img.mlx, data->sprt.x, data->sprt.y);
		data->redraw = 0;
		printf("RENDER: %d,%d\n", data->sprt.x, data->sprt.y); fflush(stdout);
	}
}