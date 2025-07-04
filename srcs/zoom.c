/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:19:55 by stephan           #+#    #+#             */
/*   Updated: 2025/06/23 12:55:44 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fract *fractal, double x, double y, int direction)
{
	double	zoom;
	double	mouse_x;
	double	mouse_y;

	zoom = 1.2;
	mouse_x = (x - fractal->width / 2.0)
		/ (0.25 * fractal->zoom * fractal->width) + fractal->x_shift;
	mouse_y = (y - fractal->height / 2.0)
		/ (0.25 * fractal->zoom * fractal->height) + fractal->y_shift;
	if (direction > 0)
	{
		fractal->zoom *= zoom;
		fractal->x_shift = mouse_x - (mouse_x - fractal->x_shift) / zoom;
		fractal->y_shift = mouse_y - (mouse_y - fractal->y_shift) / zoom;
	}
	else
	{
		fractal->zoom /= zoom;
		fractal->x_shift = mouse_x - (mouse_x - fractal->x_shift) * zoom;
		fractal->y_shift = mouse_y - (mouse_y - fractal->y_shift) * zoom;
	}
	return ;
}
