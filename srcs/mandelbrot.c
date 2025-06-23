/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:04:27 by stephan           #+#    #+#             */
/*   Updated: 2025/06/23 12:56:47 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	mandelbrot_color(t_fract *fractal, double zx, double zy)
{
	int		i;
	double	tmp;
	double	cx;
	double	cy;

	i = 0;
	cx = zx;
	cy = zy;
	while (i < fractal->iter)
	{
		if (zx * zx + zy * zy >= 4.0)
			break ;
		tmp = zx * zx - zy * zy + cx;
		zy = 2.0 * zx * zy + cy;
		zx = tmp;
		i++;
	}
	if (i == fractal->iter)
		return (0x000000FF);
	return (get_color(i, fractal->iter, fractal->color_shift));
}

void	mandelbrot(t_fract *fractal)
{
	int		x;
	int		y;
	double	zx;
	double	zy;

	y = 0;
	if (!fractal || !fractal->image || fractal->width <= 0
		|| fractal->height <= 0)
		return ;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			zx = (x - fractal->width / 2.0)
				/ (0.25 * fractal->zoom * fractal->width) + fractal->x_shift;
			zy = (y - fractal->height / 2.0)
				/ (0.25 * fractal->zoom * fractal->height) + fractal->y_shift;
			mlx_put_pixel(fractal->image, x, y,
				mandelbrot_color(fractal, zx, zy));
			x++;
		}
		y++;
	}
}
