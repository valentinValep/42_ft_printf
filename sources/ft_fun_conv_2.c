#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_integer_conv(va_list *args)
{
	return (ft_itoa(va_arg(*args, int)));
}

char	*ft_unsigned_conv(va_list *args)
{
	return (ft_itoa_unsigned(va_arg(*args, int)));
}

char	*ft_lower_hexa_conv(va_list *args)
{
	return (ft_itoa_hexa(va_arg(*args, int), 1));
}

char	*ft_upper_hexa_conv(va_list *args)
{
	return (ft_itoa_hexa(va_arg(*args, int), 0));
}

char	*ft_percent_conv(va_list *args)
{
	char *const	res = malloc((1 + 1) * sizeof(char));

	if (!res)
		return (NULL);
	(void) args;
	res[0] = '%';
	res[1] = 0;
	return (res);
}
