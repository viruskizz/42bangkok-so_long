#include "libft.h"
#include <stdio.h>
#include <mlx.h>

int	main(void)
{
	// void	*img;
	// void	*mlx;

	// mlx = mlx_init();
	// img = mlx_new_image(mlx, 1920, 1080);
	printf("Hello MLX\n");
	ft_putstr_fd("TEST Libft\n", 1);

	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
	printf("win %p\n", win);
    mlx_loop(mlx);
}
