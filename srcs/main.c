/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:01:45 by stephan           #+#    #+#             */
/*   Updated: 2025/06/23 12:29:57 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_hook(void *param)
{
	t_fract	*fractal;

	fractal = param;
	ft_memset(fractal->image->pixels, 0,
		fractal->image->width * fractal->image->height * sizeof(int32_t));
	input_fractal(fractal);
}

int	input_fractal(t_fract *fractal)
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

int	is_valid_float(char *str)
{
	int	digits;
	int	i;

	digits = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		digits = 1;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (0);
		while (ft_isdigit(str[i]))
		{
			digits = 1;
			i++;
		}
	}
	if (!digits || str[i] != '\0')
		return (0);
	return (1);
}

//check for integers if float or int and then pass
int	check_arg(t_fract *fractal, int argc, char **argv)
{
	if (argc < 2 || argc > 4)
		return (error_usage(), 0);
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractal->name = "mandelbrot";
		return (1);
	}
	if (argc == 4 && ft_strncmp("julia", argv[1], 6) == 0)
	{
		if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
			return (error_usage(), 0);
		fractal->name = "julia";
		fractal->julia_cx = ft_atof(argv[2]);
		fractal->julia_cy = ft_atof(argv[3]);
		if (fractal->julia_cx < -2.0 || fractal->julia_cx > 2.0
			|| fractal->julia_cy < -2.0 || fractal->julia_cy > 2.0)
			return (ft_printf("Julia parameters invalid."), error_usage(), 0);
		return (1);
	}
	return (error_usage(), 0);
}

int	main(int argc, char **argv)
{
	t_fract	fractal;

	if (!check_arg(&fractal, argc, argv))
		return (clean_exit(&fractal), 1);
	fractal.name = argv[1];
	init_fract(&fractal);
	if (!init_mlx(&fractal))
		return (clean_exit(&fractal), 1);
	if (!input_fractal(&fractal))
		return (error_usage(), clean_exit(&fractal), 1);
	mlx_key_hook(fractal.mlx, key_hook, &fractal);
	mlx_scroll_hook(fractal.mlx, &scroll_hook, &fractal);
	mlx_loop_hook(fractal.mlx, &ft_hook, &fractal);
	mlx_close_hook(fractal.mlx, (void (*)(void *))clean_exit, &fractal);
	mlx_loop(fractal.mlx);
	clean_exit(&fractal);
	return (EXIT_SUCCESS);
}
