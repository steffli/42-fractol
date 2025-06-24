/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:55:33 by stephan           #+#    #+#             */
/*   Updated: 2025/06/24 16:18:15 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_usage(void)
{
	ft_printf("Usage: ./fractol [fractal_name]\n");
	ft_printf("Avaiable fractals:\n - mandelbrot\n - julia\n");
	ft_printf("If you use Julia the numbers must be between -2.0 and 2.0");
	ft_printf("Here some paramaters with meaningful fractals:\n");
	ft_printf("-0.8\t\t0.156\n−0.70176\t−0.3842\n−0.835\t\t− 0.2321");
	exit(1);
}

void	clean_exit(t_fract *fractal)
{
	if (fractal->image)
		mlx_delete_image(fractal->mlx, fractal->image);
	if (fractal->mlx)
		mlx_terminate(fractal->mlx);
	exit(EXIT_SUCCESS);
}

void	exit_hook(void *param)
{
	t_fract	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		clean_exit(fractal);
}

void	error(void)
{
	ft_printf("Error");
	exit(1);
}
