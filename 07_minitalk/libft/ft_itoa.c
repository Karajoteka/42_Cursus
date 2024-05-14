/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:56:44 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 13:03:27 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Using malloc(3), generate a string that represents the integer value 
   received as an argument. Negative numbers should be handled. */

#include "libft.h"

static int	num_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;
	int		is_negative;

	nbr = n;
	len = num_length(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		nbr = -nbr;
	}
	str = (char *)malloc(sizeof(char) * len + is_negative + 1);
	if (!str)
		return (NULL);
	if (is_negative)
		str[0] = '-';
	str[len + is_negative] = '\0';
	while (len-- > 0)
	{
		str[len + is_negative] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
