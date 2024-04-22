/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:43:57 by agu               #+#    #+#             */
/*   Updated: 2023/11/27 12:33:24 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compares the first (at most) n bytes of s1 and s2.It returns an integer less 
 * than, equal to, or greater than zero if s1 is found,respectively, to be less 
 * than, to match, orbe greater than s2. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
