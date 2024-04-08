/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:37:48 by agu               #+#    #+#             */
/*   Updated: 2023/11/30 10:06:16 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns a pointer to the last occurrence of the char c in the string s. */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (i == 0 && (unsigned char)c != '\0')
		return ((char *) NULL);
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	i--;
	while (i > 0)
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return ((char *) NULL);
}
