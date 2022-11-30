#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

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

char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
void	ft_long_to_hexa(unsigned long long nbr, char *output, int i);
char	*ft_itoa_hexa(unsigned int n, int lower);

#endif
