/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:55:33 by stephan           #+#    #+#             */
/*   Updated: 2025/06/20 12:27:22 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    error_usage(void)
{
    ft_printf("Usage: ./fractol [fractal_name]\n");
    ft_printf("Avaiable fractals:\n - mandelbrot\n - julia");
    exit(1);
}

void clean_exit(t_fract *fractal)
{
    if (fractal->image)
        mlx_delete_image(fractal->mlx, fractal->image);
    if (fractal->mlx)
        mlx_terminate(fractal->mlx);
    exit(EXIT_SUCCESS);
}

void exit_hook(void *param)
{
    t_fract *fractal;

    fractal = param;
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
        clean_exit(fractal);
}
