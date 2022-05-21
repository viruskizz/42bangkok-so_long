#ifndef SO_LONG_H
#define SO_LONG_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define SPIRIT_SIZE     64

#define GREEN_PIXEL 0x00FF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF

#define MLX_ERROR 1

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17

#define KEY_LEFT			123
#define KEY_RIGHT			124
#define KEY_UP				126
#define KEY_DOWN			125
#define KEY_A				0
#define KEY_S				1
#define KEY_D				2
#define KEY_W				13

#include <stdint.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_rect
{
    int x;
    int y;
    int width;
    int height;
    int color;
}   t_rect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	char	*name;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		redraw;
	t_img	img;
	t_img	background;
	t_img	sprite;
}	t_data;

int	render(t_data *data);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	img_pix_put(t_img *img, int x, int y, int color);
t_img	render_img(t_data *data, char *filename, int x, int y);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
int 	keyhandler(int keycode, t_data *data);
#endif
