/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:29:16 by agu               #+#    #+#             */
/*   Updated: 2023/11/30 13:17:26 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the substring of the given string at the given start position with 
 * the given length (or smaller if the length of the original string is less 
 * than start + length, or length is bigger than MAXSTRINGLEN).*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s || len <= 0 || (start >= s_len))
	{
		substr = (char *)malloc(1);
		if (substr)
			*substr = '\0';
		return (substr);
	}
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
