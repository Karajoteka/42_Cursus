/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:27:37 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/05/13 19:59:17 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bit(pid_t pid, char bit)
{
	int	signum;

	if (bit == '0')
		signum = SIGUSR1;
	else
		signum = SIGUSR2;
	if (kill(pid, signum) == -1)
	{
		ft_printf("Error: cannot send bit\n");
		exit(EXIT_FAILURE);
	}
	usleep(100);
}

void	send_string(pid_t pid, char *str)
{
	int		i;
	int		j;
	char	bit;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] >> j) & 1)
				bit = '1';
			else
				bit = '0';
			send_bit(pid, bit);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <string>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
