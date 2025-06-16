/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:56:18 by stliu             #+#    #+#             */
/*   Updated: 2025/03/24 16:51:42 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		ft_putc(s[i]);
		(*count)++;
		i++;
	}
}

void	ft_hex(unsigned int n, int *count, const char *format)
{

	if (n >= 16)
		ft_hex(n / 16, count, format);
	if (n % 16 < 10)
	{
		ft_putc(n % 16 + '0'); //error = 
		(*count)++;
	}
	else //else if (error != -1)
	{
		if ((*format == 'X'))
			ft_putc(n % 16 + 'A' - 10);
		else
			ft_putc(n % 16 + 'a' - 10);
		(*count)++;
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putc('-');
		n = -n;
		(*count)++;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	ft_putc((n % 10 + '0'));
	(*count)++;
}

void	ft_unsigned(unsigned int n, int *count)
{
	if (n >= 10)
		ft_unsigned(n / 10, count);
	ft_putc((n % 10 + '0'));
	(*count)++;
}
