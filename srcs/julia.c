/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:04:23 by stephan           #+#    #+#             */
/*   Updated: 2025/06/19 15:51:55 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t julia_color(t_fract *fractal, double zx, double zy)
{
    int i;
    double tmp;

    i = 0;
    while (i < fractal->iter)
    {
        if (zx * zx + zy * zy >= 4.0)
            break;
        tmp = zx * zx - zy * zy + fractal->julia_cx;
        zy = 2.0 * zx * zy + fractal->julia_cy;
        zx = tmp;
        i++;
    }
    if (i == fractal->iter)
        return 0x000000FF;
    return get_color(i, fractal->iter, fractal->color_shift);
}

void julia(t_fract *fractal)
{
    int x;
    int y;
    double zx;
    double zy;

    y = 0;
    if (!fractal || !fractal->image) 
        return;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            zx = (x - WIDTH/2.0) / (0.25 * fractal->zoom * WIDTH) + fractal->x_shift;
            zy = (y - HEIGHT/2.0) / (0.25 * fractal->zoom * HEIGHT) + fractal->y_shift;
            mlx_put_pixel(fractal->image, x, y, julia_color(fractal, zx, zy));
            x++;
        }
        y++;
    }
}
