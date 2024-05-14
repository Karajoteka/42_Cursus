/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:14:11 by agu               #+#    #+#             */
/*   Updated: 2023/11/27 12:27:34 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Scans the initial n bytes of the memory area pointed to by s for the first 
 * instance of c.  Both c and the bytes of the memory area pointed to by s are 
 * interpreted as unsigned char. */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
