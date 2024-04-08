/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:48:58 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/13 18:35:45 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putunbr(unsigned int n)
{
	char			temp_buffer[11];
	int				i;
	unsigned int	counter;

	counter = 0;
	i = 0;
	if (n == 0)
		counter += write(1, "0", 1);
	while (n > 0)
	{
		temp_buffer[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (i > 0)
	{
		i--;
		counter += write(1, &temp_buffer[i], 1);
	}
	return (counter);
}
