#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	(void) format;
	va_end(args);
	return (0);
}