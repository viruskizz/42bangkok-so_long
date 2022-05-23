#include "so_long.h"

static t_tile	new_tile(t_data *data, char type, int x, int y)
{
	t_tile	tile;
	t_img	img;

	tile.type = type;
	tile.x = x;
	tile.y = y;
	// img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	if (type == '1')
		img.mlx = mlx_xpm_file_to_image(data->mlx, OBJECT_WALL_PATH, &img.width, &img.height);
	else if (type == 'E')
		img.mlx = mlx_xpm_file_to_image(data->mlx, OBJECT_EXIT_PATH, &img.width, &img.height);
	else
		img.mlx = NULL;	
	tile.img = img;
	return (tile);
}

void	load_map(t_data *data)
{
	char	*str;
	int		i;
	int		j;

	// printf("w:d = %d:%d\n", data->map.width, data->map.height);
	// printf("x:y = %d:%d\n", data->map.tile_x, data->map.tile_y);
	data->map.tiles = malloc(sizeof(t_tile*) * data->map.tile_y);
	i = 0;
	str = data->map.filedata;
	while (*str)
	{
		j = 0;
		data->map.tiles[i] = malloc(sizeof(t_tile) * data->map.tile_x);
		while (*str != '\n' && *str)
		{
			data->map.tiles[i][j] = new_tile(data, *str, j * TILE_SIZE, i * TILE_SIZE);
			j++;
			str++;
		}
		str++;
		i++;
	}
}

void	render_map(t_data *data)
{
	int		i;
	int		j;
	t_tile	t;

	i = 0;
	while (i < data->map.tile_y)
	{
		j = 0;
		while (j < data->map.tile_x)
		{
			t = data->map.tiles[i][j];
			if (t.img.mlx)
				mlx_put_image_to_window(data->mlx, data->win, t.img.mlx, t.x, t.y);
			j++;
		}
		i++;
	}
}	
