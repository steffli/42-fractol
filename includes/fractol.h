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

// typedef struct  s_mlx
// {
//     void* window;
//     void* context;
//     int32_t width;
//     int32_t height;
//     double  delta_time;
// } mlx_t;

// typedef struct  s_keyhooks
// {
//     keys_t  key;
//     action_t    action;
// }mlx_key_t;

void    error_usage(void);

#endif