/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:13:55 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 08:13:56 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUF_SIZE			4098
# define SPIRIT_SIZE		64
# define TILE_SIZE			64

# define EXIT_SUCCEED		1
# define EXIT_FAILURE		1

# define ERROR_MLX 			1
# define ERROR_WIN			2
# define ERROR_FILE_OPEN	10
# define ERROR_FILE_TYPE	11
# define ERROR_MAP_INVALID	20

# define OBJECT_WALL_PATH	"images/objects_64x64/wall.xpm"
# define OBJECT_ITEM_PATH	"images/objects_64x64/elixir.xpm"
# define OBJECT_GRASS_PATH	"images/objects_64x64/grass.xpm"
# define OBJECT_EXIT_PATH	"images/objects_64x64/door.xpm"
# define SPRITE_SQUALL_PATH	"images/sprites_64x64/lightning_stand.xpm"

# ifdef __linux__
#  define IS_LINUX 1
#  define OS "LINUX"
# else
#  define IS_LINUX 0
#  define OS "MAC"
# endif

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include "key.h"
# include "ft_printf.h"

# define MAP_FILE	"maps/simple.ber"

typedef struct s_img
{
	void	*mlx;
	char	*addr;
	char	*name;
	int		w;
	int		h;
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
	int		items;
	int		moved;
	t_img	img;
}	t_sprt;

typedef struct s_map
{
	char	*filedata;
	int		width;
	int		height;
	int		tile_x;
	int		tile_y;
	int		items;
	t_tile	**tiles;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		render;
	t_tile	*bg;
	t_sprt	sprt;
	t_tile	*objs;
	t_map	map;
}	t_data;

void	load_file(t_data *data, char *filename);
void	load_background(t_data *data);
void	render_background(t_data *data);
void	load_objects(t_data *data);
void	render_object(t_data *data);
void	collect_object(t_data *data);
void	load_sprites(t_data *data);
void	render_sprite(t_data *data);
void	move_sprite(t_data *data, int nx, int ny);
void	chk_pos_sprite(t_data *data);
void	exit_game(t_data *data, int code);
void	error_game(t_data *data, int code);
void	load_map(t_data *data);
void	render_map(t_data *data);
t_tile	get_tile(t_data *data, int x, int y);

#endif
