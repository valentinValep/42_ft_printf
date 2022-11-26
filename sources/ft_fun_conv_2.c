
#include <stdio.h>
char	*ft_unsigned_conv(va_list *args)
{
	(void) args;
	printf("ft_unsigned_conv");
	return ("42");
}

char	*ft_lower_hexa_conv(va_list *args)
{
	(void) args;
	printf("ft_lower_hexa_conv");
	return ("2a");
}

char	*ft_upper_hexa_conv(va_list *args)
{
	(void) args;
	printf("ft_upper_hexa_conv");
	return ("2A");
}

char	*ft_percent_conv(va_list *args)
{
	(void) args;
	printf("ft_percent_conv");
	return ("%%");
}
