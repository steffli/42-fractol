/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:52:57 by stephan           #+#    #+#             */
/*   Updated: 2025/06/19 15:30:01 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    key_hook(mlx_key_data_t hook, void *param)
{
    t_fract *fractal;
    double move;

    fractal = param;
    move = 0.1 / fractal->zoom;
    if (hook.key == MLX_KEY_ESCAPE && hook.action == MLX_PRESS)
    {
        mlx_close_window(fractal->mlx);
        return ;
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
        else if (hook.key == MLX_KEY_R)
            init_fract(fractal);
    }
    input_fractal(fractal, fractal->name);
}

void scroll_hook(double xdelta, double ydelta, void *param)
{
    t_fract *fractal = param;
    
    (void)xdelta;
    int32_t mouse_x;
    int32_t mouse_y;
    mlx_get_mouse_pos(fractal->mlx, &mouse_x, &mouse_y);
    if (ydelta > 0)
        zoom(fractal, mouse_x, mouse_y, 1);
    else if (ydelta < 0)
        zoom(fractal, mouse_x, mouse_y, -1);
}
