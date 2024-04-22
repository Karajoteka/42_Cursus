/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:25:07 by agu               #+#    #+#             */
/*   Updated: 2023/11/27 12:34:08 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates memory (with malloc(3)) and returns the string that is
 * a copy of 's1', without the characters specified in 'set' at the beginning and
 * end of the string. */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*newstring;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
		end--;
	newstring = ft_substr(s1, 0, end + 1);
	return (newstring);
}
