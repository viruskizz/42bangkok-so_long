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
				data->sprt.items = 0;
				data->sprt.moved = 0;
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
}

void	move_sprite(t_data *data, int nx, int ny)
{
	t_tile		nt;

	nt = get_tile(data, data->sprt.x + nx, data->sprt.y + ny);
	if (nt.type == '1')
		return ;
	data->sprt.x += nx;
	data->sprt.y += ny;
	data->sprt.moved++;
	printf("MOVED: %d", data->sprt.moved);
	chk_pos_sprite(data);
}

void	chk_pos_sprite(t_data *data)
{
	t_tile	t;

	t = get_tile(data, data->sprt.x, data->sprt.y);
	if (t.type == 'E')
	{
		if (data->map.items == data->sprt.items)
			exit_game(data);
	}
}