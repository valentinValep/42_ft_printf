
#include <stdio.h>
char	*ft_char_conv(va_list *args)
{
	(void) args;
	printf("ft_char_conv");
	return ("A");
}

char	*ft_string_conv(va_list *args)
{
	(void) args;
	printf("ft_string_conv");
	return ("ABC");
}

char	*ft_pointer_conv(va_list *args)
{
	(void) args;
	printf("ft_pointer_conv");
	return ("0x42424242");
}

char	*ft_decimal_conv(va_list *args)
{
	(void) args;
	printf("ft_decimal_conv");
	return ("42");
}

char	*ft_integer_conv(va_list *args)
{
	(void) args;
	printf("ft_integer_conv");
	return ("42");
}
