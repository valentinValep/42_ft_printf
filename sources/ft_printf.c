#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

//char *(*fun_list[CONVERSION_NUMBER])(void *); = {&ft_char_conv,
//	&ft_string_conv, &ft_pointer_conv, &ft_decimal_conv, &ft_integer_conv,
//	&ft_unsigned_conv, &ft_lower_hexa_conv, &ft_upper_hexa_conv,
//	&ft_percent_conv};
static char	*ft_fun_conv(char c, va_list *args)
{
	int			i;
	const char	format_list[CONVERSION_NUMBER] = {'c', 's', 'p', 'd', 'i', 'u',
		'x', 'X', '%'};
	t_fun_conv	*fun_list;

	fun_list = (t_fun_conv [CONVERSION_NUMBER]){&ft_char_conv,
		&ft_string_conv, &ft_pointer_conv, &ft_decimal_conv, &ft_integer_conv,
		&ft_unsigned_conv, &ft_lower_hexa_conv, &ft_upper_hexa_conv,
		&ft_percent_conv};
	i = -1;
	while (++i < CONVERSION_NUMBER && format_list[i] != c)
		;
	if (i == CONVERSION_NUMBER)
		return (NULL);
	return (fun_list[i](args));
}

//static void	*ft_get_arg(char c, va_list args)
//{
//	int			i;
//	const char	format_list[CONVERSION_NUMBER] = {'c', 's', 'p', 'd', 'i', 'u',
//		'x', 'X', '%'};
//	t_fun_conv	*fun_list;

//	fun_list = (t_fun_conv [CONVERSION_NUMBER]){&ft_char_conv,
//		&ft_string_conv, &ft_pointer_conv, &ft_decimal_conv, &ft_integer_conv,
//		&ft_unsigned_conv, &ft_lower_hexa_conv, &ft_upper_hexa_conv,
//		&ft_percent_conv};

//}

static int	ft_strlen_printf(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strjoin_printf(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	len = ft_strlen_printf(s1) + ft_strlen_printf(s2);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return ((char *)(long)(s1 && (free(s1), 0)));
	res[len] = 0;
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i++] = s2[j];
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	char	*res;

	res = NULL;
	va_start(args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			if (!ft_strjoin_printf(res, ft_fun_conv(format[++i], &args)))
				return (-1);
	}
	va_end(args);
	return (write(STDOUT_FILENO, res, len));
}
