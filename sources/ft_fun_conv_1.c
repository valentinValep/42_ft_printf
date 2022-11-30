#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_itoa(int n);

char	*ft_char_conv(va_list *args)
{
	char *const	c = malloc((1 + 1) * sizeof(char));

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
	res[i] = 0;
	i = -1;
	while (str[++i])
		res[i] = str[i];
	return (res);
}

char	*ft_pointer_conv(va_list *args)
{
	char				*res;
	unsigned long long	addr;
	int					i;

	res = malloc((15) * sizeof(char));
	res[0] = '0';
	res[1] = 'x';
	i = 1;
	while (++i < 14)
		res[i] = '0';
	addr = (unsigned long long) va_arg(*args, unsigned long long);
	long_to_hexa((unsigned long long) addr, res, 13);
	return (res);
}

char	*ft_decimal_conv(va_list *args)
{
	return (ft_itoa(va_arg(*args, int)));
}
