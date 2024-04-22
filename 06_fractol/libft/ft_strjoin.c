/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:19:28 by agu               #+#    #+#             */
/*   Updated: 2023/11/27 12:32:42 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Concatenates two strings. */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstring;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	newstring = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	return (newstring);
}
