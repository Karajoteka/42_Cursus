/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:21:38 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/13 18:35:58 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_conversions(const char *flag, va_list args)
{
	if (*flag == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*flag == 'd' || *flag == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*flag == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (*flag == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (*flag == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (*flag == 'p')
		return (ft_puthexptr(va_arg(args, void *)));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				length += write(1, "%", 1);
			else
				length += ft_conversions(&str[i + 1], args);
			i++;
		}
		else
			length += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (length);
}
