/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:55:33 by stephan           #+#    #+#             */
/*   Updated: 2025/06/16 17:06:52 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    error_usage(void)
{
    ft_printf("Usage: ./fractol [fractal_name]\n");
    ft_printf("Avaiable fractals:\n - mandelbrot\n - julia");
    return ;
}