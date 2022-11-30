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
	while (str && str[++i])
		;
	res = malloc((i + 1 + (!str * 7)) * sizeof(char));
	if (!res)
		return (NULL);
	if (!str)
		return (res[++i] = '(', res[++i] = 'n', res[++i] = 'u',
			res[++i] = 'l', res[++i] = 'l', res[++i] = ')', res[++i] = 0, res);
	res[i] = 0;
	i = -1;
	while (str[++i])
		res[i] = str[i];
	return (res);
}

static char	*ft_return_nil(void)
{
	char	*res;
	int		i;

	res = malloc((6) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	return (res[i++] = '(', res[i++] = 'n', res[i++] = 'i',
		res[i++] = 'l', res[i++] = ')', res[i++] = 0, res);
}

char	*ft_pointer_conv(va_list *args)
{
	char				*res;
	unsigned long long	addr;
	unsigned long long	cpy;
	int					i;
	int					len;

	addr = (unsigned long long) va_arg(*args, unsigned long long);
	if (!addr)
		return (ft_return_nil());
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
	i = 1;
	while (++i < len + 2)
		res[i] = '0';
	ft_long_to_hexa((unsigned long long) addr, res, len + 1);
	return (res[0] = '0', res[1] = 'x', res[len + 2] = 0, res);
}

char	*ft_decimal_conv(va_list *args)
{
	return (ft_itoa(va_arg(*args, int)));
}
