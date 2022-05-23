#include "so_long.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

// t_img	render_img(t_data *data, char *filename, int x, int y)
// {
// 	t_img	img;
	
// 	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, filename, &img.width, &img.height);
// 	data->img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, x, y);
// 	return (img);
// }

int	render_rect(t_img *img, t_rect rect)
{
	
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

// void	render_background(t_data *data) 
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	data->background.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	data->background.addr = mlx_get_data_addr(data->background.mlx_img, &data->background.bpp, &data->background.line_len, &data->background.endian);
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH)
// 			img_pix_put(&data->background, j++, i, GREEN_PIXEL);
// 		++i;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.mlx_img, 0, 0);
// }
void	set_background(t_data *data) 
{
	int	x;
	int	y;
	t_tile	*bg;
	t_tile	*t;

	x = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			t = malloc(sizeof(t_tile));
			t->x = x;
			t->y = y;
			t->type = '0';
			// t->img.addr = mlx_get_data_addr(t->img.mlx_img, &t->img.bpp, &t->img.line_len, &t->img.endian);
			t->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, OBJECT_GRASS_PATH, &t->img.width, &t->img.height);
			t->next = NULL;
			t->previous = NULL;
			if (x == 0 && y == 0)
				data->background = t;
			else
				bg->next = t;
			bg = t;
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

void	render_background(t_data *data) 
{
	t_tile	*bg;

	bg = data->background;
	while (bg)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, bg->img.mlx_img, bg->x, bg->y);
		bg = bg->next;
	}
}
