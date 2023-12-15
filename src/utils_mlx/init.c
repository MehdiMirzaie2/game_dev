
#include "game.h"
#include <mlx.h>

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, SWIDTH, SHEIGHT, "minimlx");
	mlx->image = mlx_new_image(mlx->mlx, SWIDTH, SHEIGHT);
	mlx->pointer_to_image = mlx_get_data_addr(mlx->image,
			&mlx->bits_per_pixel,
			&mlx->size_line,
			&mlx->endian);
}
