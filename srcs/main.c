/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:01:45 by stephan           #+#    #+#             */
/*   Updated: 2025/06/20 12:29:13 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error(void)
{
    ft_printf("Error");
    exit(EXIT_FAILURE);
}

static void ft_hook(void *param)
{
    t_fract *fractal;
    
    fractal = param;
    ft_memset(fractal->image->pixels, 0, fractal->image->width * fractal->image->height * sizeof(int32_t));
    input_fractal(fractal, fractal->name);
}

int input_fractal(t_fract *fractal, char *input)
{
    if (ft_strncmp("mandelbrot", input, 11) == 0)
    {
        fractal->name = "mandelbrot";
        mandelbrot(fractal);
        return (1);
    }
    else if (ft_strncmp("julia", input, 6) == 0)
    {   
        fractal->name = "julia";    
        julia(fractal);
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_fract fractal;
    
    if (argc != 2 || (argc == 2 && argv[1][0] == '\0'))
        error_usage();
    init_fract(&fractal);
    mlx_set_setting(MLX_MAXIMIZED, true);
    fractal.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
    if (!fractal.mlx)
        error();
    fractal.image = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
    if (!fractal.image || (mlx_image_to_window(fractal.mlx, fractal.image, 0, 0) < 0))
        error();
    if (!input_fractal(&fractal, argv[1]))
        error_usage();
    mlx_key_hook(fractal.mlx, key_hook, &fractal);
    mlx_scroll_hook(fractal.mlx, &scroll_hook, &fractal);
    mlx_loop_hook(fractal.mlx, &ft_hook, &fractal);
    mlx_close_hook(fractal.mlx,(void(*)(void*))clean_exit, &fractal);
    mlx_loop(fractal.mlx);
    clean_exit(&fractal);
    return (EXIT_SUCCESS);
    // fractal = malloc(size_of(fracatal));
    // mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
    // if (!mlx)
    //     error();
    // mlx_image_t *image = mlx_new_image(mlx, WIDTH, HEIGHT);
    // if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
    //     error();
    // mlx_put_pixel(image, 300, 300, 000000);
    // mlx_key_hook(fractal, &ft_keyhook, NULL);
    // mlx_scroll_hook(fractal, &ft_mousehook, NULL);
    // mlx_loop_hook(mlx, ft_hook, mlx);
    // mlx_loop(mlx);
    // mlx_terminate(mlx);
}
