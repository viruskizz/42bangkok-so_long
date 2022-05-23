#ifndef SO_LONG_H
#define SO_LONG_H

#define WINDOW_WIDTH		1600
#define WINDOW_HEIGHT		1200
#define SPIRIT_SIZE			64
#define TILE_SIZE			64

#define GREEN_PIXEL			0x00FF00
#define RED_PIXEL			0xFF0000
#define WHITE_PIXEL			0xFFFFFF

#define MLX_ERROR 1

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17

#define KEY_ESC				53
#define KEY_LEFT			123
#define KEY_RIGHT			124
#define KEY_UP				126
#define KEY_DOWN			125
#define KEY_A				0
#define KEY_S				1
#define KEY_D				2
#define KEY_W				13

#define OBJECT_WALL_PATH	"images/objects_64x64/wall.xpm"
#define OBJECT_ITEM_PATH	"images/objects_64x64/elixir.xpm"
#define OBJECT_GRASS_PATH	"images/objects_64x64/grass.xpm"
#define OBJECT_EXIT_PATH	"images/objects_64x64/door.xpm"
#define SPRITE_SQUALL_PATH	"images/sprites_64x64/squall.xpm"

# ifdef __linux__
#  define IS_LINUX 1
#  define OS "LINUX"
# else
#  define IS_LINUX 0
#  define OS "MAC"
# endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft.h"

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
	void	*mlx;
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

typedef struct s_tile
{
	char			type;
	int				x;
	int				y;
	t_img			img;
	struct s_tile	*next;
}	t_tile;

typedef struct s_sprt
{
	int		x;
	int		y;
	t_img	img;
}	t_sprt;

typedef struct s_map
{
	char	*filedata;
	int		width;
	int		height;
	int		tile_x;
	int		tile_y;
	t_tile	**tiles;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_tile	*bg;
	t_sprt	sprt;
	t_tile	*objs;
	t_map	map;
}	t_data;

void	read_file(t_data *data, char *filename);
int		render(t_data *data);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	img_pix_put(t_img *img, int x, int y, int color);
t_img	render_img(t_data *data, char *filename, int x, int y);
int		render_rect(t_img *img, t_rect rect);
void	set_background(t_data *data);
void	render_background(t_data *data);
void 	load_objects(t_data *data);
void	render_object(t_data *data);
void	load_sprites(t_data *data);
void	render_sprite(t_data *data);
void	exit_game(t_data *data);
void	load_map(t_data *data);
void	render_map(t_data *data);
#endif
