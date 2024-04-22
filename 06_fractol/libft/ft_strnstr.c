/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:40 by agu               #+#    #+#             */
/*   Updated: 2023/11/27 12:33:50 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Locates the first occurrence	of the null-terminated string little in the 
 * null-terminated string big.*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	i = 0;
	l_len = ft_strlen(little);
	if (little[0] == '\0' || big == little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && little[j] != '\0'
			&& big[i + j] == little[j] && i + j < len)
			j++;
		if (j == l_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
