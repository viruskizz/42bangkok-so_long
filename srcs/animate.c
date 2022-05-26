#include "so_long.h"

int		collecting_animate(t_data *data, char *act, int delay)
{
	ft_printf("collecting\n");
	int		time;
	t_img	img;

	time = 0;
	delay = delay * 1000 * 1000;
	while (time < delay)
		time++;
	if (ft_strncmp("SIT", act, 3) == 0)
	{
		printf("SIT\n");
		mlx_destroy_image(data->mlx, data->sprt.img.mlx);
		img.mlx = mlx_xpm_file_to_image(data->mlx, SPRITE_KNEEL_PATH, &img.w, &img.h);

	}
	else if (ft_strncmp("STAND", act, 5) == 0)
	{
		printf("STAND\n");
		mlx_destroy_image(data->mlx, data->sprt.img.mlx);
		img.mlx = mlx_xpm_file_to_image(data->mlx, SPRITE_STAND_PATH, &img.w, &img.h);
	}
	data->sprt.img = img;
	// data->sprt.img = img;
	ft_printf("end\n");
	return (1);
}

int		walking_animate(t_sprt *sprt, int x, int y)
{
	return (0);
}