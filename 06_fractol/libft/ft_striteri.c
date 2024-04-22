/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:03:18 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 13:08:33 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* For each character in the string 's', apply the function 'f', using the 
   character's index within 's' and the address of the character itself 
   as parameters. The character can be modified if necessary. */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
