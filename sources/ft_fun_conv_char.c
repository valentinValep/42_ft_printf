#include <stdarg.h>
#include "ft_printf.h"

void	ft_char_conv(va_list *args, t_display_buffer *buf)
{
	ft_write_buf(buf, &(char){va_arg(*args, int)}, 1);
}

void	ft_string_conv(va_list *args, t_display_buffer *buf)
{
	int		i;
	char	*str;

	str = (char *)va_arg(*args, char const *);
	if (!str)
	{
		ft_write_buf(buf, "(null)", 6);
		return ;
	}
	i = -1;
	while (str[++i])
		;
	ft_write_buf(buf, str, i);
}

void	ft_percent_conv(va_list *args, t_display_buffer *buf)
{
	(void)args;
	ft_write_buf(buf, "%", 1);
}
