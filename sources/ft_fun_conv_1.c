#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_itoa(int n);

t_string	ft_char_conv(va_list *args)
{
	t_string	res;

	res.str = malloc((1 + 1) * sizeof(char));
	if (!res.str)
		return (res);
	res.len = 1;
	res.str[1] = 0;
	res.str[0] = (char) va_arg(*args, int);
	return (res);
}

t_string	ft_string_conv(va_list *args)
{
	t_string	res;
	const char	*str;
	int			i;

	str = (const char *) va_arg(*args, char const *);
	if (!str)
	{
		res.str = malloc(7 * sizeof(char));
		if (!res.str)
			return (res);
		return (res.len = 6, res.str[0] = '(', res.str[1] = 'n',
			res.str[2] = 'u', res.str[3] = 'l', res.str[4] = 'l',
			res.str[5] = ')', res.str[6] = 0, res);
	}
	res.len = -1;
	while (str[++res.len])
		;
	res.str = malloc((res.len + 1) * sizeof(char));
	if (!res.str)
		return (res);
	res.str[res.len] = 0;
	i = -1;
	while (++i < res.len)
		res.str[i] = str[i];
	return (res);
}

t_string	ft_pointer_conv(va_list *args)
{
	t_string			res;
	unsigned long long	addr;
	unsigned long long	cpy;
	int					i;

	addr = (unsigned long long) va_arg(*args, unsigned long long);
	if (!addr)
	{
		res.str = malloc(6 * sizeof(char));
		if (!res.str)
			return (res);
		return (res.len = 5, res.str[0] = '(', res.str[1] = 'n',
			res.str[2] = 'i', res.str[3] = 'l', res.str[4] = ')',
			res.str[5] = 0, res);
	}
	res.len = 2;
	cpy = addr;
	while (cpy)
	{
		cpy /= 16;
		res.len++;
	}
	res.str = malloc((res.len + 1) * sizeof(char));
	if (!res.str)
		return (res);
	i = 1;
	while (++i < res.len)
		res.str[i] = '0';
	ft_long_to_hexa((unsigned long long) addr, res.str, res.len - 1);
	return (res.str[0] = '0', res.str[1] = 'x', res.str[res.len] = 0, res);
}

t_string	ft_decimal_conv(va_list *args)
{
	t_string	res;

	res.str = ft_itoa(va_arg(*args, int));
	if (!res.str)
		return (res);
	res.len = ft_strlen(res.str);
	return (res);
}
