/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:51:11 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/13 18:35:52 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthexptr(void *ptr)
{
	char				temp_buffer[17];
	char				*hex_digits;
	unsigned long long	hex;
	int					i;
	unsigned int		counter;

	counter = 0;
	hex_digits = "0123456789abcdef";
	hex = (unsigned long long)ptr;
	i = 0;
	if (hex == 0)
		temp_buffer[i++] = '0';
	while (hex > 0)
	{
		temp_buffer[i++] = hex_digits[hex % 16];
		hex = hex / 16;
	}
	counter += write(1, "0x", 2);
	if (i == 0)
		counter += write(1, "0", 1);
	while (i-- > 0)
		counter += write(1, &temp_buffer[i], 1);
	return (counter);
}
