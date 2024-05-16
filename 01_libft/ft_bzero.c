/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:01:51 by agu               #+#    #+#             */
/*   Updated: 2023/12/05 19:28:45 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Erases the data in the n bytes of the memory starting at the location 
 *pointed to by s, by writing zeros (bytes containing '\0') to that area.*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
