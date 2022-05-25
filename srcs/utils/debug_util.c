#include "so_long.h"

void	inspect_map(t_data *data, char attr)
{
	t_map map;

	map = data->map;
	if (attr == 'F')
		ft_printf("%s\n", map.filedata);
	ft_printf("== [%d] x [%d] ==\n", map.tile_x, map.tile_y);
	ft_printf("== %d x %d ==\n", map.width, map.height);
	ft_printf("[C] = %d\n", map.items);
	ft_printf("[E] = %d\n", map.exits);
	ft_printf("[P] = %d\n", map.sprts);
}
