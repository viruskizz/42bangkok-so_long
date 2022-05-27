#include "so_long.h"

static t_sprt	initial_boss(t_data *data, int gx, int gy)
{
	t_sprt b;

	b.x = gx * TILE_SIZE;
	b.y = gy * TILE_SIZE;
	b.nx = b.x;
	b.ny = b.y;
	b.animating = 0;
	b.act = ACT_STAND;
	b.face = DIRCT_DOWN;
	b.item = 0;
	b.moved = 0;
	b.img = set_img(data, SPRITE_STAND_DOWN_PATH);
	return (b);
}

void	load_boss(t_data *data)
{
	int	gx;
	int	gy;

	gy = 0;
	// while (gy < data->map_gr)
}
