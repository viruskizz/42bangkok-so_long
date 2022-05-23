#include "so_long.h"

void load_objects(t_data *data)
{
	int		i;
	int		j;
	t_tile	*obj;
	t_tile	*tmp;

	i = 0;
	while (i < data->map.tile_y)
	{
		j = 0;
		while (j < data->map.tile_x)
		{
			if (data->map.tiles[i][j].type == 'C')
			{
				obj = malloc(sizeof(t_tile));
				obj->type = 'C';
				obj->x = j * TILE_SIZE;
				obj->y = i * TILE_SIZE;
				obj->img.mlx = mlx_xpm_file_to_image(data->mlx, OBJECT_ITEM_PATH, &obj->img.width, &obj->img.height); 
				obj->next = NULL;
				if (data->objs)
					tmp->next = obj;
				else
					data->objs = obj;
				tmp = obj;
			}
			j++;
		}	
		i++;
	}
}

void	render_object(t_data *data)
{
	t_tile *obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->img.mlx)
			mlx_put_image_to_window(data->mlx, data->win, obj->img.mlx, obj->x, obj->y);
		obj = obj->next;
	}
}

void	collect_object(t_data *data)
{
	t_tile	t;
	t_tile	*obj;

	t = get_tile(data, data->sprt.x, data->sprt.y);
	if (t.type == 'C')
	{
		obj = data->objs;
		while (obj)
		{
			if (obj->x == t.x && obj->y == t.y)
			{
				data->sprt.items++;
				obj->img.mlx = NULL;
				return ;
			}
			obj = obj->next;
		}
	}
}