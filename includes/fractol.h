/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:50:00 by stephan           #+#    #+#             */
/*   Updated: 2025/06/18 13:36:49 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include "../libs/Libft/libft.h"
#include "../libs/printf/ft_printf.h"
#include "../libs/MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>

#define HEIGHT  1000
#define WIDTH   1000

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_R  15
# define KEY_C  8
# define KEY_SPACE 49
# define MOUSE_UP 4
# define MOUSE_DOWN 5 


typedef struct s_fractol
{
    mlx_t *mlx;
    // void *window;
    mlx_image_t *image;
    double zoom;
    double x;
    double y;
    double x_shift;
    double y_shift;
    char    *name;
    int iter;
    int color_shift;
    u_int32_t color;
}t_fract;

//Inits
void    init_fract(t_fract *fractal);
void    init_mlx(t_fract *fractal);

//Thresh Q
void    key_hook(mlx_key_data_t keydata, void *param);
void    scroll_hook(double xdelta, double ydelta, void*param);

//Fractals
void    mandelbrot(t_fract *fractal);
void    julia(t_fract *fractal);

//Utilities
void    error_usage(void);
void    error(void);
void    zoom(t_fract *fractal, double x, double y, int direction);
int     input_fractal(t_fract *fractal, char *input);



#endif