/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:08:55 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 13:09:33 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* For each character in the string 's', apply the function 'f', using the 
   character's index within 's' and the character itself as parameters. 
   Generate a new string with the result of the successive use of 'f'. */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*newstring;

	len = ft_strlen(s);
	newstring = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstring[i] = f(i, s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
