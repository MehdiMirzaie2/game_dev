/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:40:29 by clovell           #+#    #+#             */
/*   Updated: 2023/12/14 10:21:49 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "game.h"
#include "utils_mlx.h"

void	put_color_to_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	*buffer;

	buffer = mlx->pointer_to_image;
	buffer[(y * mlx->size_line / 4) + x] = color;
}

void	render(t_mlx *mlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y < SHEIGHT)
	{
		x = -1;
		while (++x < SWIDTH)
		{
			put_color_to_pixel(mlx, x, y, 0xff0000);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}


int	main(int ac, char **av)
{
	t_mlx	*mlx = malloc(sizeof(t_mlx));
	(void)av;
	(void)ac;
	init_mlx(mlx);
	mlx_loop_hook(mlx->mlx, (void *)render, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
