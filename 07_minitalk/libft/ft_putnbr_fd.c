/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:45:45 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 13:06:35 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Send the number 'n' to the given file descriptor. */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp_buffer[11];
	int		i;

	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		temp_buffer[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (i > 0)
	{
		i--;
		write(fd, &temp_buffer[i], 1);
	}
}
