#ifndef SO_LONG_H
#define SO_LONG_H

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define GREEN_PIXEL 0x00FF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF

#define MLX_ERROR 1

#include <stdint.h>
#include <stdlib.h>
#include <mlx.h>
#include "shape.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
// int		render_rect(t_data *data, t_rect rect);
// void	render_background(t_data *data, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
#endif
