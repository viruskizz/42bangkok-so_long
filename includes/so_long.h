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

# define RED_PIXEL			0xEB4034

# define EXIT_SUCCEED		1
# define EXIT_FAILURE		1

# define ERROR_MLX 			1
# define ERROR_WIN			2
# define ERROR_FILE_OPEN	10
# define ERROR_FILE_TYPE	11
# define ERROR_MAP_INVALID	20

# define OBJECT_WALL_PATH			"objects/wall.xpm"
# define OBJECT_ITEM_PATH			"objects/elixir_small.xpm"
# define OBJECT_GRASS_PATH			"objects/grass.xpm"
# define OBJECT_EXIT_PATH			"objects/door.xpm"
# define SPRITE_STAND_LEFT_PATH		"players/cele_stand_left.xpm"
# define SPRITE_STAND_RIGHT_PATH	"players/cele_stand_right.xpm"
# define SPRITE_STAND_UP_PATH		"players/cele_stand_up.xpm"
# define SPRITE_STAND_DOWN_PATH		"players/cele_stand_down.xpm"
# define SPRITE_KNEEL_PATH			"players/cele_sit.xpm"
# define SPRITE_HURT_PATH			"players/cele_hurt.xpm"
# define SPRITE_FALLEN_PATH			"players/cele_fallen.xpm"
# define SPRITE_WALK_LEFT1_PATH		"players/cele_walk_left_1.xpm"
# define SPRITE_WALK_LEFT2_PATH		"players/cele_walk_left_2.xpm"
# define SPRITE_WALK_RIGHT1_PATH	"players/cele_walk_right_1.xpm"
# define SPRITE_WALK_RIGHT2_PATH	"players/cele_walk_right_2.xpm"
# define SPRITE_WALK_UP1_PATH		"players/cele_walk_up_1.xpm"
# define SPRITE_WALK_UP2_PATH		"players/cele_walk_up_2.xpm"
# define SPRITE_WALK_DOWN1_PATH		"players/cele_walk_down_1.xpm"
# define SPRITE_WALK_DOWN2_PATH		"players/cele_walk_down_2.xpm"
# define BOSS_PATH					"bosses/altos.xpm"
# define ENEMY_STAND_LEFT_PATH		"enemies/ghost_stand_left.xpm"
# define ENEMY_STAND_RIGHT_PATH		"enemies/ghost_stand_right.xpm"
# define ENEMY_STAND_BACK_PATH		"enemies/ghost_stand_back.xpm"
# define ENEMY_STAND_FRONT_PATH		"enemies/ghost_stand_front.xpm"
# define ENEMY_WALK_LEFT1_PATH		"enemies/ghost_walk_left_1.xpm"
# define ENEMY_WALK_LEFT2_PATH		"enemies/ghost_walk_left_2.xpm"
# define ENEMY_WALK_RIGHT1_PATH		"enemies/ghost_walk_right_1.xpm"
# define ENEMY_WALK_RIGHT2_PATH		"enemies/ghost_walk_right_2.xpm"
# define ENEMY_WALK_UP1_PATH		"enemies/ghost_walk_back_1.xpm"
# define ENEMY_WALK_UP2_PATH		"enemies/ghost_walk_back_2.xpm"
# define ENEMY_WALK_DOWN1_PATH		"enemies/ghost_walk_front_1.xpm"
# define ENEMY_WALK_DOWN2_PATH		"enemies/ghost_walk_front_2.xpm"

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

// # define MAP_FILE	"maps/simple.ber"
// # define MAP_FILE	"maps/errors/test"
// # define MAP_FILE	"maps/errors/empty.ber"
// # define MAP_FILE	"maps/errors/not_rect.ber"
// # define MAP_FILE	"maps/errors/no_file.ber"
// # define MAP_FILE	"maps/errors/no_exit.ber"
// # define MAP_FILE	"maps/errors/no_item.ber"
// # define MAP_FILE	"maps/errors/no_sprite.ber"
// # define MAP_FILE	"maps/errors/no_wall.ber"
# define MAP_FILE		"maps/simple.ber"
// # define MAP_FILE	"maps/large.ber"
# define ACT_STAND		0
# define ACT_SIT		1
# define ACT_WALK		2
# define ACT_WALK_L		21
# define ACT_WALK_R		22
# define ACT_COLLECTED	3
# define ACT_HURTING	4
# define ACT_FALLEN		9

# define DIRCT_LEFT		1
# define DIRCT_UP		2
# define DIRCT_RIGHT	3
# define DIRCT_DOWN		4

typedef struct s_vtr
{
	int		x;
	int		y;
} t_vtr;

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
}	t_img;

typedef struct s_tile
{
	char			type;
	t_vtr			v;
	t_img			img;
	struct s_tile	*next;
}	t_tile;

typedef struct s_sprt
{
	t_vtr	v;
	t_vtr	nv;
	int		act;
	int		n_act;
	int		face;
	int		item;
	int		moved;
	unsigned int	animating;
	t_img	img;
}	t_sprt;

typedef struct s_map
{
	char	*filedata;
	int		width;
	int		height;
	int		grid_x;
	int		grid_y;
	int		item;
	int		exit;
	int		player;
	int		boss;
	int		enemy;
	t_tile	**tiles;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		render;
	t_tile	*bg;
	t_sprt	player;
	t_sprt	boss;
	t_sprt	emenies;
	t_tile	*objs;
	t_map	map;
}	t_data;

void	load_file(t_data *data, char *filename);
void	load_backgrounds(t_data *data);
void	render_backgrounds(t_data *data);
void	free_backgrounds(t_data *data);

void	load_map(t_data *data);
void	validate_map(t_data *data);
void	render_map(t_data *data);

void	load_objects(t_data *data);
void	render_objects(t_data *data);
void	free_objects(t_data *data);

void	load_player(t_data *data);
void	render_player(t_data *data);

void	player_standing(t_data *data);
void	player_walking(t_data *data);
void	player_collect(t_data *data);
void	player_moving(t_data *data);
void	player_hurting(t_data *data);

void	moving_handling(t_data *data, int dirct, int dx, int dy);
void	space_handling(t_data *data);
void	stand_rhandling(t_data *data);

void	load_boss(t_data *data);
void	render_boss(t_data *data);

void	chk_pos_player(t_data *data);
void	exit_game(t_data *data, int code);
void	error_game(t_data *data, int code, char *msg);

t_tile	get_tile(t_data *data, int x, int y);
int		get_direction(int cur_x, int cur_y, int nxt_x, int nxt_y);
t_img	set_img(t_data *data, char *path);
int	is_ovelap_tile(t_vtr v1, t_vtr v2, t_vtr o1, t_vtr o2);
void	inspect_map(t_data *data, char attr);

#endif
