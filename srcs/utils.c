/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:59 by stephan           #+#    #+#             */
/*   Updated: 2025/06/23 12:13:09 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color(int iter, int max_iter, int shift)
{
	double	t;
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;

	if (iter >= max_iter)
		return (0x000000FF);
	t = (double)(iter + shift) / max_iter;
	b = (uint8_t)(155 + 100 * sin(t * M_PI * 10.0));
	g = (uint8_t)(b * 0.4);
	r = (uint8_t)(b * 0.1);
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

static double	float_value(char *str, int pos)
{
	double	num;
	double	factor;

	num = 0.0;
	factor = 1.0;
	while (ft_isdigit(str[pos]))
	{
		num *= 10;
		num += (str[pos] - '0');
		pos++;
	}
	if (str[pos] == '.')
	{
		pos++;
		while (ft_isdigit(str[pos]))
		{
			factor /= 10;
			num += (str[pos] - '0') * factor;
			pos++;
		}
	}
	return (num);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	num;

	i = 0;
	sign = 1;
	num = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	num = float_value(str, i);
	return (sign * num);
}
