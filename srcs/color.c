/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:59 by stephan           #+#    #+#             */
/*   Updated: 2025/06/20 12:24:33 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t get_color(int iter, int max_iter, int shift)
{
    if (iter >= max_iter)
        return (0x000000FF);
    double t = (double)(iter + shift) / max_iter;
    uint8_t b = (uint8_t)(155 + 100 * sin(t * M_PI * 10.0));
    uint8_t g = (uint8_t)(b * 0.4);
    uint8_t r = (uint8_t)(b * 0.1);
    
    return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}
