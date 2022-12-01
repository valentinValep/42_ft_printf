#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static t_string	ft_fun_conv(char c, va_list *args)
{
	int					i;
	const char			format_list[CONVERSION_NUMBER] = "cspdiuxX%";
	t_fun_conv const	fun_list[CONVERSION_NUMBER] = {&ft_char_conv,
		&ft_string_conv, &ft_pointer_conv, &ft_decimal_conv, &ft_integer_conv,
		&ft_unsigned_conv, &ft_lower_hexa_conv, &ft_upper_hexa_conv,
		&ft_percent_conv};
	t_string			res;


	i = -1;
	while (++i < CONVERSION_NUMBER && format_list[i] != c)
		;
	if (i == CONVERSION_NUMBER)
		return ((t_string){NULL, 0});
	res = fun_list[i](args);
	return (res);
}

static int	ft_strlen_printf(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

static char	*ft_join_printf(t_display_buffer *buf, t_string s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s2.str)
		return ((char *)(long)(buf->buffer && (free(buf->buffer), 0)));
	buf->len = ft_strlen_printf(buf->buffer) + s2.len;
	res = malloc((buf->len + 1) * sizeof(char));
	if (!res)
		return ((char *)(long)(buf->buffer && (free(buf->buffer), 0)));
	res[buf->len] = 0;
	i = -1;
	while (buf->buffer + ++i && buf->buffer[i])
		res[i] = buf->buffer[i];
	j = -1;
	while (++j + i < buf->len)
		res[i + j] = s2.str[j];
	free(buf->buffer);
	free((char *)s2.str);
	return (res);
}

static char	*ft_strjoin_printf(t_display_buffer *buf, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	buf->len = ft_strlen_printf(buf->buffer) + ft_strlen_printf(s2);
	res = malloc((buf->len + 1) * sizeof(char));
	if (!res)
		return ((char *)(long)(buf->buffer && (free(buf->buffer), 0)));
	res[buf->len] = 0;
	i = -1;
	while (buf->buffer + ++i && buf->buffer[i])
		res[i] = buf->buffer[i];
	j = -1;
	while (++j + i < buf->len)
		res[i + j] = s2[j];
	free(buf->buffer);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list				args;
	int					i;
	t_display_buffer	res;

	if (!format)
		return (-1);
	res.buffer = NULL;
	va_start(args, format);
	i = -1;
	res.len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			res.buffer = ft_join_printf(&res,
					ft_fun_conv(format[++i], &args));
		else
		{
			res.buffer = ft_strjoin_printf(&res, format + i);
			i += ft_strlen_printf(format + i) - 1;
		}
		if (!res.buffer)
			return (-1);
	}
	va_end(args);
	res.len = write(STDOUT_FILENO, res.buffer, res.len);
	free(res.buffer);
	return (res.len);
}
