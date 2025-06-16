#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		check_format(va_list args, const char *format, int *count);
int		ft_putc(char c);
void	ft_putstr(char *s, int *count);
void	ft_hex(unsigned int n, int *count, const char *format);
void	ft_putnbr(int n, int *count);
void	ft_unsigned(unsigned int n, int *count);
void	ft_ptr(unsigned long long ptr, int *count);

#endif