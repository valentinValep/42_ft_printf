/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_conv_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:17:03 by vlepille          #+#    #+#             */
/*   Updated: 2022/12/02 12:17:03 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "ft_printf.h"

static void	ft_putnbr_hex(unsigned int nbr, t_display_buffer *buf, int lower)
{
	if (nbr / 16)
		ft_putnbr_hex(nbr / 16, buf, lower);
	ft_write_buf(buf, &(char []){"0123456789ABCDEF0123456789abcdef"}[nbr % 16
		+ (!!lower) * 16], 1);
}

static void	ft_putnbr_addr(size_t nbr, t_display_buffer *buf, int lower)
{
	if (nbr / 16)
		ft_putnbr_addr(nbr / 16, buf, lower);
	ft_write_buf(buf, &(char []){"0123456789ABCDEF0123456789abcdef"}[nbr % 16
		+ (!!lower) * 16], 1);
}

void	ft_pointer_conv(va_list *args, t_display_buffer *buf)
{
	size_t	input;

	input = (size_t)va_arg(*args, void *);
	if (!input)
	{
		ft_write_buf(buf, "(nil)", 5);
		return ;
	}
	ft_write_buf(buf, "0x", 2);
	ft_putnbr_addr(input, buf, 1);
}

void	ft_lower_hexa_conv(va_list *args, t_display_buffer *buf)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr_hex(input, buf, 1);
}

void	ft_upper_hexa_conv(va_list *args, t_display_buffer *buf)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr_hex(input, buf, 0);
}
