#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

static t_tile	*new_tile(t_data *data, char type, int x, int y)
{
	t_tile	*tile;
	t_img	img;

	tile = malloc(sizeof(t_tile));
	tile->type = type;
	img.x = x;
	img.y = y;
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	if (type == '1')
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, OBJECT_WALL_PATH, &img.width, &img.height);
	else if (type == 'E')
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, OBJECT_EXIT_PATH, &img.width, &img.height);
	else if (type == 'C')
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, OBJECT_ITEM_PATH, &img.width, &img.height);
	else
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, OBJECT_GRASS_PATH, &img.width, &img.height);
	tile->img = img;
	tile->previous = NULL;
	tile->next = NULL;
	return (tile);
}
void	connect_tile(t_tile *tile, t_tile *new)
{
	t_tile *tmp;

	if (!tile)
		tile = new;
	tmp = tile;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
}

void	render_map(t_data *data)
{
	t_tile	*tile;

	tile = data->tiles;
	while (tile)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, tile->img.mlx_img, tile->img.x, tile->img.y);
		tile = tile->next;
	}
}

void	load_map(t_data *data)
{
	int	fd;
	int	i;
	int	x;
	int	y;
	char *line;
	t_tile	*tile;

	(void) data;
	fd = open("maps/simple.ber", O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	y = 0;
	while (line && *line)
	{
		i = 0;
		x = 0;
		printf("%s", line);
		while (line[i] != '\n' && line[i] != '\0')
		{
			tile = new_tile(data, line[i++], x, y);
			if (x == 0 && y == 0)
				data->tiles = tile;
			else
				connect_tile(data->tiles, tile);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
		free(line);
		printf(">>%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("\nFIN\n"); fflush(stdout);
}