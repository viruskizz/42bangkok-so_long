#include "so_long.h"

void	set_background(t_data *data) 
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	data->bg = malloc(sizeof(t_tile) * data->map.tile_x * data->map.tile_y * 1000);
	if (!data->bg)
	{
		printf("ERROR MALLOC\n"); fflush(stdout);
		return ;
	}
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			data->bg[i].x = x;
			data->bg[i].y = y;
			data->bg[i].type = '0';
			data->bg[i].img.mlx = mlx_xpm_file_to_image(data->mlx, OBJECT_GRASS_PATH, &data->bg[i].img.width, &data->bg[i].img.height);
			x += TILE_SIZE;
			i++;
		}
		y += TILE_SIZE;
	}
}

void	render_background(t_data *data) 
{
	int		i;
	t_tile	bg;

	i = 0;
	while (i < data->map.tile_x * data->map.tile_y)
	{
		bg = data->bg[i];
		if (bg.img.mlx)
			mlx_put_image_to_window(data->mlx, data->win, bg.img.mlx, bg.x, bg.y);
		i++;
	}
}

void	free_background(t_data *data)
{

}