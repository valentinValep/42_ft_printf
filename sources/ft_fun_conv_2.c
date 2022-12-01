#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

t_string	ft_integer_conv(va_list *args)
{
	t_string	res;

	res.str = ft_itoa(va_arg(*args, int));
	if (!res.str)
		return (res);
	res.len = ft_strlen(res.str);
	return (res);
}

t_string	ft_unsigned_conv(va_list *args)
{
	t_string	res;

	res.str = ft_itoa_unsigned(va_arg(*args, int));
	if (!res.str)
		return (res);
	res.len = ft_strlen(res.str);
	return (res);
}

t_string	ft_lower_hexa_conv(va_list *args)
{
	t_string	res;

	res.str = ft_itoa_hexa(va_arg(*args, int), 1);
	if (!res.str)
		return (res);
	res.len = ft_strlen(res.str);
	return (res);
}

t_string	ft_upper_hexa_conv(va_list *args)
{
	t_string	res;

	res.str = ft_itoa_hexa(va_arg(*args, int), 0);
	if (!res.str)
		return (res);
	res.len = ft_strlen(res.str);
	return (res);
}

t_string	ft_percent_conv(va_list *args)
{
	t_string	res;

	(void) args;
	res.str = malloc((1 + 1) * sizeof(char));
	if (!res.str)
		return (res);
	res.len = 1;
	res.str[0] = '%';
	res.str[1] = 0;
	return (res);
}
