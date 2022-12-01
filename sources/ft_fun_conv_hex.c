#include <stdarg.h>
#include <stddef.h>
#include "ft_printf.h"

static void	ft_putnbr_hex(unsigned int nbr, t_display_buffer *buf, int lower)
{
	if (nbr / 16)
		ft_putnbr_hex(nbr / 16, buf, lower);
	ft_write_buf(buf, &(char []){"0123456789ABCDEF0123456789abcdef"}[nbr % 16
		+ (!!lower) * 16], 1);
}

void	ft_pointer_conv(va_list *args, t_display_buffer *buf)
{
	int	input;

	input = (size_t)va_arg(*args, void *);
	if (!input)
	{
		ft_write_buf(buf, "(nil)", 5);
		return ;
	}
	ft_write_buf(buf, "0x", 2);
	ft_putnbr_hex(input, buf, 1);
}

void	ft_lower_hexa_conv(va_list *args, t_display_buffer *buf)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr_hex(input, buf, 1);
}

void	ft_upper_hexa_conv(va_list *args, t_display_buffer *buf)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr_hex(input, buf, 0);
}
