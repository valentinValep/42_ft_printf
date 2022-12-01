#include <stdarg.h>
#include "ft_printf.h"

static void	ft_putnbr(int nbr, t_display_buffer *buf)
{
	if (nbr / 10)
		ft_putnbr(nbr / 10, buf);
	else
		ft_write_buf(buf, "-", nbr < 0);
	ft_write_buf(buf, &(char){nbr % 10 * ((nbr > 0) * 2 -1) + '0'}, 1);
}

static void	ft_putnbr_unsigned(unsigned int nbr, t_display_buffer *buf)
{
	if (nbr / 10)
		ft_putnbr_unsigned(nbr / 10, buf);
	ft_write_buf(buf, &(char){nbr % 10 + '0'}, 1);
}

void	ft_decimal_conv(va_list *args, t_display_buffer *buf)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr(input, buf);
}

void	ft_integer_conv(va_list *args, t_display_buffer *buf)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr(input, buf);
}

void	ft_unsigned_conv(va_list *args, t_display_buffer *buf)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr_unsigned(input, buf);
}
