#include "so_long.h"

// int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char	*pixel;

// 	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(int *)pixel = color;
// }


// int	render_rect(t_img *img, t_rect rect)
// {
	
// 	int	i;
// 	int	j;

// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			img_pix_put(img, j++, i, rect.color);
// 		++i;
// 	}
// 	return (0);
// }

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