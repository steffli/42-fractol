/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:06:49 by stliu             #+#    #+#             */
/*   Updated: 2025/03/24 17:50:07 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(unsigned long long n, int *count)
{
	if (n >= 16)
		print_ptr(n / 16, count);
	if (n % 16 < 10)
	{
		ft_putc(n % 16 + '0');
		(*count)++;
	}
	else
	{
		ft_putc(n % 16 + 'a' - 10);
		(*count)++;
	}
}

void	ft_ptr(unsigned long long ptr, int *count)
{
	ft_putstr("0x", count);
	print_ptr((unsigned long long)ptr, count);
}
