/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:49:59 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/13 18:35:54 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex(unsigned int hex, int uppercase)
{
	char			temp_buffer[9];
	char			*hex_digits;
	int				i;
	unsigned int	counter;

	counter = 0;
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (hex == 0)
		counter += write(1, "0", 1);
	i = 0;
	while (hex > 0)
	{
		temp_buffer[i++] = hex_digits[hex % 16];
		hex = hex / 16;
	}
	while (i-- > 0)
		counter += write(1, &temp_buffer[i], 1);
	return (counter);
}
