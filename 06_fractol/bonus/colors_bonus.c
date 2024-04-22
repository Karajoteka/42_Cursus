/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:30:01 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/04/18 19:26:04 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_color(int iterations, t_mlx_data *data)
{
	int	r;
	int	g;
	int	b;

	if (iterations == MAX_ITERATIONS)
		return (0x000000);
	if (data->color_mode == 0)
	{
		r = (iterations * 5) % 256;
		g = (iterations * 10) % 256;
		b = (iterations * 15) % 256;
	}
	else
	{
		r = (int)(255 * (1 + cos(iterations / 64.0)));
		g = (int)(255 * (1 + cos((iterations / 64.0) + (2 * M_PI / 3))));
		b = (int)(255 * (1 + cos((iterations / 64.0) + (4 * M_PI / 3))));
	}
	return ((r << 16) | (g << 8) | b << 4);
}
