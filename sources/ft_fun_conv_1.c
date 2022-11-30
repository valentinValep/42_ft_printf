#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_itoa(int n);

char	*ft_char_conv(va_list *args)
{
	char *const	c = malloc((1 + 1) * sizeof(char));

	if (!c)
		return (NULL);
	c[1] = 0;
	c[0] = (char) va_arg(*args, int);
	return (c);
}

char	*ft_string_conv(va_list *args)
{
	char		*res;
	const char	*str;
	int			i;

	str = (const char *) va_arg(*args, char const *);
	i = -1;
	while (str[++i])
		;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[i] = 0;
	i = -1;
	while (str[++i])
		res[i] = str[i];
	return (res);
}
#include <stdio.h>
char	*ft_pointer_conv(va_list *args)
{
	char				*res;
	unsigned long long	addr;
	unsigned long long	cpy;
	int					i;
	int					len;

	addr = (unsigned long long) va_arg(*args, unsigned long long);
	len = 0;
	cpy = addr;
	while (cpy)
	{
		cpy /= 16;
		len++;
	}
	res = malloc((len + 3) * sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	res[len + 2] = 0;
	i = 1;
	while (++i < len + 2)
		res[i] = '0';
	ft_long_to_hexa((unsigned long long) addr, res, len + 1);
	return (res);
}

char	*ft_decimal_conv(va_list *args)
{
	return (ft_itoa(va_arg(*args, int)));
}
