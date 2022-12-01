#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define CONVERSION_NUMBER 9

int		ft_printf(const char *format, ...);

typedef struct s_string {
	char	*str;
	int		len;
}	t_string;

typedef t_string	(*t_fun_conv)(va_list *);

t_string	ft_char_conv(va_list *args);
t_string	ft_string_conv(va_list *args);
t_string	ft_pointer_conv(va_list *args);
t_string	ft_decimal_conv(va_list *args);
t_string	ft_integer_conv(va_list *args);
t_string	ft_unsigned_conv(va_list *args);
t_string	ft_lower_hexa_conv(va_list *args);
t_string	ft_upper_hexa_conv(va_list *args);
t_string	ft_percent_conv(va_list *args);

char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
void	ft_long_to_hexa(unsigned long long nbr, char *output, int i);
char	*ft_itoa_hexa(unsigned int n, int lower);

typedef struct s_display_buffer {
	char	*buffer;
	int		len;
}	t_display_buffer;

int	ft_strlen(char *str);

#endif
