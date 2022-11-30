/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:14:14 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/30 16:14:27 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_long_to_hexa(unsigned long long nbr, char *output, int i)
{
	const unsigned long long int	div = nbr / 16;

	output[i] = "0123456789abcdef"[nbr % 16];
	if (div == 0)
		return ;
	ft_long_to_hexa(div, output, i - 1);
}
