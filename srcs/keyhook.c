/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:52:57 by stephan           #+#    #+#             */
/*   Updated: 2025/06/18 14:04:29 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    key_hook(mlx_key_data_t hook, void *param)
{
    t_fract *fractal = param;
    
    if (hook.key == MLX_KEY_ESCAPE && hook.action == MLX_PRESS)
    {
        mlx_close_window(fractal->mlx);
        return ;
    }
    if (hook.action == MLX_PRESS || hook.action == MLX_REPEAT)
    {    
        if (hook.key == KEY_UP)
            fractal->x_shift = fractal->y_shift - 10 / fractal->zoom;
        else if (hook.key == KEY_DOWN)
            fractal->x_shift = fractal->y_shift + 10 / fractal->zoom;
        else if (hook.key == KEY_LEFT)
            fractal->x_shift = fractal->x_shift - 10 / fractal->zoom;
        else if (hook.key == KEY_RIGHT)
            fractal->x_shift = fractal->x_shift + 10 / fractal->zoom;
        else if (hook.key == KEY_R)
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