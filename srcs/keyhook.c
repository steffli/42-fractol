/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:52:57 by stephan           #+#    #+#             */
/*   Updated: 2025/06/23 13:03:27 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook(mlx_key_data_t hook, void *param)
{
	t_fract	*fractal;
	double	move;

	fractal = param;
	move = 0.1 / fractal->zoom;
	if (hook.key == MLX_KEY_ESCAPE && hook.action == MLX_PRESS)
	{
		mlx_close_window(fractal->mlx);
		exit(EXIT_SUCCESS);
	}
	if (hook.action == MLX_PRESS || hook.action == MLX_REPEAT)
	{
		if (hook.key == MLX_KEY_UP)
			fractal->y_shift -= move;
		else if (hook.key == MLX_KEY_DOWN)
			fractal->y_shift += move;
		else if (hook.key == MLX_KEY_LEFT)
			fractal->x_shift -= move;
		else if (hook.key == MLX_KEY_RIGHT)
			fractal->x_shift += move;
	}
	input_fractal(fractal);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fract	*fractal;
	int32_t	mouse_x;
	int32_t	mouse_y;

	fractal = param;
	(void)xdelta;
	mlx_get_mouse_pos(fractal->mlx, &mouse_x, &mouse_y);
	if (ydelta > 0)
		zoom(fractal, mouse_x, mouse_y, 1);
	else if (ydelta < 0)
		zoom(fractal, mouse_x, mouse_y, -1);
}

void	resize_hook(int width, int height, void *param)
{
	t_fract	*fractal;

	fractal = param;
	if (width <= 0 || height <= 0)
		return ;
	if (fractal->image)
		mlx_delete_image(fractal->mlx, fractal->image);
	fractal->image = mlx_new_image(fractal->mlx, width, height);
	if (!fractal->image)
	{
		error();
		return ;
	}
	fractal->width = width;
	fractal->height = height;
	if (mlx_image_to_window(fractal->mlx, fractal->image, 0, 0) < 0)
	{
		error();
		return ;
	}
	input_fractal(fractal);
}
