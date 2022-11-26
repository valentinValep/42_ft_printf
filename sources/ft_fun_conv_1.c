#include <stdlib.h>
#include <stdarg.h>

char	*ft_char_conv(va_list *args)
{
	char *const	c = malloc((1 + 1) * sizeof(char));

	c[1] = 0;
	c[0] = (char) va_arg(*args, int);
	return (c);
}

char	*ft_string_conv(va_list *args)
{
	char *const	res = malloc((3 + 1) * sizeof(char));

	(void) args;
	res[0] = 'A';
	res[1] = 'B';
	res[2] = 'C';
	res[3] = 0;
	return (res);
}

char	*ft_pointer_conv(va_list *args)
{
	char *const	res = malloc((4 + 1) * sizeof(char));

	(void) args;
	res[0] = '0';
	res[1] = 'x';
	res[2] = '4';
	res[3] = '2';
	res[4] = 0;
	return (res);
}

char	*ft_decimal_conv(va_list *args)
{
	char *const	res = malloc((2 + 1) * sizeof(char));

	(void) args;
	res[0] = '4';
	res[1] = '2';
	res[2] = 0;
	return (res);
}

char	*ft_integer_conv(va_list *args)
{
	char *const	res = malloc((2 + 1) * sizeof(char));

	(void) args;
	res[0] = '4';
	res[1] = '2';
	res[2] = 0;
	return (res);
}
