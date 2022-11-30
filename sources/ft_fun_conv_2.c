#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

char	*ft_integer_conv(va_list *args)
{
	char *const	res = malloc((2 + 1) * sizeof(char));

	(void) args;
	res[0] = '4';
	res[1] = '2';
	res[2] = 0;
	return (res);
}

char	*ft_unsigned_conv(va_list *args)
{
	char *const	res = malloc((2 + 1) * sizeof(char));

	(void) args;
	res[0] = '4';
	res[1] = '2';
	res[2] = 0;
	return (res);
}

char	*ft_lower_hexa_conv(va_list *args)
{
	char *const	res = malloc((2 + 1) * sizeof(char));

	(void) args;
	res[0] = '2';
	res[1] = 'a';
	res[2] = 0;
	return (res);
}

char	*ft_upper_hexa_conv(va_list *args)
{
	char *const	res = malloc((2 + 1) * sizeof(char));

	(void) args;
	res[0] = '2';
	res[1] = 'A';
	res[2] = 0;
	return (res);
}

char	*ft_percent_conv(va_list *args)
{
	char *const	res = malloc((1 + 1) * sizeof(char));

	(void) args; // @TODO Important to increment the va arg counter of 1
	res[0] = '%';
	res[1] = 0;
	return (res);
}
