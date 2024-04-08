/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:18:05 by agu               #+#    #+#             */
/*   Updated: 2023/11/27 12:29:30 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memcmp() function compares the first n bytes (each
 * interpreted as unsigned char) of the memory areas s1 and s2.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*byte_s1;
	const unsigned char	*byte_s2;

	byte_s1 = s1;
	byte_s2 = s2;
	while (n > 0)
	{
		if (*byte_s1 != *byte_s2)
			return (*byte_s1 - *byte_s2);
		byte_s1++;
		byte_s2++;
		n--;
	}
	return (0);
}
