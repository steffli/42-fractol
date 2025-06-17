/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:01:45 by stephan           #+#    #+#             */
/*   Updated: 2025/06/17 11:08:02 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void error(void)
{
    ft_printf("Error");
    exit(EXIT_FAILURE);
}

static void ft_hook(void *param)
{
    mlx_t *mlx = param;
    ft_printf("WIDTH: %d , HEIGHT: %d\n", mlx->width, mlx->height);
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc < 2)
        error_usage();
    mlx_set_setting(MLX_MAXIMIZED, true);
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
    if (!mlx)
        error();
    mlx_image_t *image = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
        error();
    mlx_put_pixel(image, 0, 0, 0xFF0000FF);
    mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
        
    return (EXIT_SUCCESS);
}