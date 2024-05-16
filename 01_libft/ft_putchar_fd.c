/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:18:02 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 13:04:24 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Send the character 'c' to the specified file descriptor. */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
