#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION_NUMBER 9

typedef char	*(*t_fun_conv)(va_list *);

int		ft_printf(const char *format, ...);

char	*ft_char_conv(va_list *args);
char	*ft_string_conv(va_list *args);
char	*ft_pointer_conv(va_list *args);
char	*ft_decimal_conv(va_list *args);
char	*ft_integer_conv(va_list *args);
char	*ft_unsigned_conv(va_list *args);
char	*ft_lower_hexa_conv(va_list *args);
char	*ft_upper_hexa_conv(va_list *args);
char	*ft_percent_conv(va_list *args);



#endif
