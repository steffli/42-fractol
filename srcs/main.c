/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:01:45 by stephan           #+#    #+#             */
/*   Updated: 2025/06/21 13:07:48 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void ft_hook(void *param)
{
    t_fract *fractal;
    
    fractal = param;
    ft_memset(fractal->image->pixels, 0, fractal->image->width * fractal->image->height * sizeof(int32_t));
    input_fractal(fractal);
}

int input_fractal(t_fract *fractal)
{
    if (ft_strncmp("mandelbrot", fractal->name, 11) == 0)
    {
        mandelbrot(fractal);
        return (1);
    }
    else if (ft_strncmp("julia", fractal->name, 6) == 0)
    {   
        julia(fractal);
        return (1);
    }
        return (0);
}
int is_valid_float(char *str)
{
    //take string and declare float type
    //compare both numbers if greater than 2 or smaller 
    //take get double and check if the double value is within the threshhold
    continue;
}
//check for integers if float or int and then pass
int check_arg(t_fract *fractal, int argc, char **argv)
{
    if (argc < 2 || argc > 4)
        return (error_usage(), 0);
    if (argc == 2 && ft_strnmp(argv[1], "mandelbrot", 11) == 0)
    {
        return (1);
    }
    if (argc == 4 && ft_strncmp("julia", argv[1], 6) == 0)
    {
        is_valid_float(argv[2]);
        is_valid_float(argv[3]);
        return (1);
    }
    return (0);
}


int main(int argc, char **argv)
{
    t_fract fractal;
    
    if (!check_arg(&fractal, argc, argv))
        error();
    init_fract(&fractal);
    fractal.name = argv[1];
    mlx_set_setting(MLX_MAXIMIZED, true);
    fractal.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
    if (!fractal.mlx)
        error();
    fractal.image = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
    if (!fractal.image || (mlx_image_to_window(fractal.mlx, fractal.image, 0, 0) < 0))
        error();
    if (!input_fractal(&fractal))
        error_usage();
    mlx_key_hook(fractal.mlx, key_hook, &fractal);
    mlx_scroll_hook(fractal.mlx, &scroll_hook, &fractal);
    mlx_loop_hook(fractal.mlx, &ft_hook, &fractal);
    mlx_close_hook(fractal.mlx,(void(*)(void*))clean_exit, &fractal);
    mlx_loop(fractal.mlx);
    clean_exit(&fractal);
    return (EXIT_SUCCESS);
}
