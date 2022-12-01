#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define CONVERSION_NUMBER 9
# define BUFFER_SIZE 512

int		ft_printf(const char *format, ...);

typedef struct s_display_buffer {
	char	buffer[BUFFER_SIZE];
	int		offset;
	int		total_length;
}	t_display_buffer;

void	ft_write_buf(t_display_buffer *buf, char const *str, int len);

typedef void	(*t_fun_conv)(va_list *, t_display_buffer *buf);

void	ft_char_conv(va_list *args, t_display_buffer *buf);
void	ft_string_conv(va_list *args, t_display_buffer *buf);
void	ft_pointer_conv(va_list *args, t_display_buffer *buf);
void	ft_decimal_conv(va_list *args, t_display_buffer *buf);
void	ft_integer_conv(va_list *args, t_display_buffer *buf);
void	ft_unsigned_conv(va_list *args, t_display_buffer *buf);
void	ft_lower_hexa_conv(va_list *args, t_display_buffer *buf);
void	ft_upper_hexa_conv(va_list *args, t_display_buffer *buf);
void	ft_percent_conv(va_list *args, t_display_buffer *buf);

char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
void	ft_long_to_hexa(unsigned long long nbr, char *output, int i);
char	*ft_itoa_hexa(unsigned int n, int lower);

#endif
