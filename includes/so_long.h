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
# define FRAME_RATE			60
# define BUF_SIZE			4098
# define SPIRIT_SIZE		64
# define TILE_SIZE			64
# define ENEMY				1
# define SCORE_LEN			4

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
// # include "mlx.h"
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
// # define MAP_FILE		"maps/simple.ber"
# define MAP_FILE		"maps/simple_mon.ber"
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
	char	type;
	t_vtr	v;
}	t_tile;

typedef struct s_sprt
{
	t_vtr	v;
	t_vtr	nv;
	t_img	img;
	char	type;
	int		act;
	int		n_act;
	int		face;
	int		item;
	int		moved;
	int		animating;
	struct s_sprt	*next;
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

typedef struct s_panel
{
	int		w;
	int		h;
	t_vtr	v;
	t_sprt	*bg;
	t_sprt	*score;
}	t_panel;


typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		frame;
	int		stime;
	int		w;
	int		h;
	t_sprt	*bg;
	t_sprt	player;
	t_sprt	boss;
	t_sprt	*enemies;
	t_sprt	*objs;
	t_map	map;
	t_panel	panel;
}	t_data;

void	load_file(t_data *data, char *filename);
void	load_map(t_data *data);
void	load_tiles(t_data *data);

void	validate_map(t_data *data);
int		validate_file_ext(char *filename);

void	initial_player(t_data *data, t_tile t);
void	new_enemy(t_data *data, t_tile t);
void	new_obj(t_data *data, t_tile t);
void	new_bg(t_data *data, t_tile t);

void	render_player(t_data *data);

void	player_standing(t_data *data);
void	player_walking(t_data *data);
void	player_collect(t_data *data);
void	player_moving(t_data *data);
void	player_hurting(t_data *data);

void	moving_handling(t_data *data, int dirct, int dx, int dy);
void	space_handling(t_data *data);

void	load_boss(t_data *data);
void	render_boss(t_data *data);

void	move_enemies(t_data *data, t_sprt *e);
void	enemy_walking(t_data *data, t_sprt *e);

void	load_panel(t_data *data);

void	load_score(t_data *data);
void	update_score(t_data *data);

void	load_game(t_data *data);
void	exit_game(t_data *data, int code);
void	error_game(t_data *data, int code, char *msg);
void	render_game(t_data *data);
void	chk_pos_player(t_data *data);

t_tile	get_tile(t_data *data, t_vtr v);
t_tile	random_free_tile(t_data *data, int r);
int		is_ovelap_tile(t_vtr v1, t_vtr v2, int o1, int o2);

t_vtr	set_vtr(int x, int y);
t_vtr	add_vtr(t_vtr v1, t_vtr v2);
t_vtr	get_move_vtr(int drct, int msize);

void	grid_loop_util(t_data *data, void (*f)(t_data*, t_tile));
void	add_sprt_list(t_sprt *list, t_sprt *new);

t_img	set_img(t_data *data, char *path);
t_img	get_number_img(t_data *data, char c, t_img *img);

void	render_sprts_util(t_data *data, t_sprt *s);
void	render_sprts_fnc_util(t_data *data, t_sprt *s, void (*f)(t_data*, t_sprt*));
void	free_sprts_util(t_data *data, t_sprt *s);

#endif
