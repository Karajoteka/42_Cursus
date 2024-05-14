/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:53:02 by agu               #+#    #+#             */
/*   Updated: 2023/11/27 12:27:08 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* checks if c is a 7-bit unsigned char value that fits into the ASCII set */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
