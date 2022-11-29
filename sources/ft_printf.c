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
	int					i;
	const char			format_list[CONVERSION_NUMBER] = "cspdiuxX%";
	t_fun_conv const	fun_list[CONVERSION_NUMBER] = {&ft_char_conv,
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

static int	ft_strlen_printf(const char *str, int ignore_percent)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (str[i] != '%' || ignore_percent))
		i++;
	return (i);
}

static char	*ft_strjoin_printf(char *s1, const char *s2, int *len, int free_2)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	if (!s2)
		return (NULL);
	*len = ft_strlen_printf(s1, 1) + ft_strlen_printf(s2, free_2);
	res = malloc((*len + 1) * sizeof(char));
	if (!res)
		return ((char *)(long)(s1 && (free(s1), 0)));
	res[*len] = 0;
	i = -1;
	while (s1 + ++i && s1[i])
		res[i] = s1[i];
	j = -1;
	k = 0;
	while (++j + i < *len)
		res[i + k++] = s2[j];
	free(s1);
	if (free_2)
		free((char *)s2);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		old_len;
	char	*res;

	res = NULL;
	va_start(args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			res = ft_strjoin_printf(res, ft_fun_conv(format[++i], &args), &len, 1);
		else
		{
			old_len = len;
			res = ft_strjoin_printf(res, format + i, &len, 0);
			i += len - old_len - 1;
		}
		if (!res)
			return (-1);
	}
	va_end(args);
	return (write(STDOUT_FILENO, res, len));
}
