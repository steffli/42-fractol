/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:49:52 by stephan           #+#    #+#             */
/*   Updated: 2025/06/23 12:12:25 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fract(t_fract *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 1.0;
	fractal->iter = 100;
	fractal->x_shift = 0;
	fractal->y_shift = 0;
}

int	init_mlx(t_fract *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!fractal->mlx)
		return (error(), 0);
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
	{
		mlx_terminate(fractal->mlx);
		error();
		return (0);
	}
	if (mlx_image_to_window(fractal->mlx, fractal->image, 0, 0) < 0)
	{
		mlx_delete_image(fractal->mlx, fractal->image);
		mlx_terminate(fractal->mlx);
		error();
		return (0);
	}
	return (1);
}
