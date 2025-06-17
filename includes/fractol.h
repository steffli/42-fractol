/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:50:00 by stephan           #+#    #+#             */
/*   Updated: 2025/06/17 11:11:09 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include "../libs/Libft/libft.h"
#include "../libs/printf/ft_printf.h"
#include <math.h>
#include "../libs/MLX42/include/MLX42/MLX42.h"

#define HEIGHT  256
#define WIDTH   256

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_R  15
# define KEY_C  8
# define KEY_SPACE 49


typedef struct f_fractol
{
    mlx_t *mlx;
    mlx_image *image;
    double zoom;
    double x;
    double y;
    int iter;
    int color_shift;
}t_fract

void    error_usage(void);
void key_hook(mlx_key_data_t keydata, void *param);

#endif