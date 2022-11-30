/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:51:22 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/30 17:16:57 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	int_len(unsigned int n)
{
	if (n / 10)
		return (1 + int_len(n / 10));
	return (1 + (n < 0));
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*res;
	int		i;

	i = int_len(n) - 1 - (n < 0);
	res = malloc((i + 2 + (n < 0)) * sizeof(char));
	if (!res)
		return (0);
	if (n < 0)
		res[0] = '-';
	res[i + 1 + (n < 0)] = 0;
	while (i >= 0)
	{
		res[i + (n < 0)] = '0' + (n % 10) * ((n > 0) * 2 - 1);
		n = n / 10;
		i--;
	}
	return (res);
}
