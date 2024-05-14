/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:47:57 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/05/14 15:41:31 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_bitfield	g_bitfield = {0, 0};

void	handle_signal(int signum)
{
	if (signum == SIGUSR1)
		g_bitfield.c |= (0 << g_bitfield.bits_received);
	else if (signum == SIGUSR2)
		g_bitfield.c |= (1 << g_bitfield.bits_received);
	g_bitfield.bits_received++;
	if (g_bitfield.bits_received == 8)
	{
		ft_printf("%c", g_bitfield.c);
		g_bitfield.c = 0;
		g_bitfield.bits_received = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error: cannot handle SIGUSR1\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: cannot handle SIGUSR2\n");
		exit(EXIT_FAILURE);
	}
	while (1)
		;
	return (0);
}
