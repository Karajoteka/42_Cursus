/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:27:54 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/04/19 16:30:24 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculate_iterations(t_fractal_vars vars)
{
	while (vars.iter < MAX_ITERATIONS)
	{
		vars.zx2 = vars.zx * vars.zx;
		vars.zy2 = vars.zy * vars.zy;
		if (vars.zx2 + vars.zy2 >= 4)
			break ;
		vars.zy = 2 * vars.zx * vars.zy + vars.cy;
		vars.zx = vars.zx2 - vars.zy2 + vars.cx;
		vars.iter++;
	}
	return (vars.iter);
}

void	draw_fractal_with_set_vars(t_mlx_data *data,
		void (*set_vars)(t_mlx_data *, int, int))
{
	int	iterations;

	data->props.y = 0;
	while (data->props.y < data->props.image_height)
	{
		data->props.x = 0;
		while (data->props.x < data->props.image_width)
		{
			set_vars(data, data->props.x, data->props.y);
			data->vars.iter = 0;
			if (ft_strcmp(data->fractal_type, "burning_ship") == 0)
				iterations = calculate_iterations_burning_ship(data->vars);
			else
				iterations = calculate_iterations(data->vars);
			if (iterations == MAX_ITERATIONS)
				mlx_put_pixel(data->img, data->props.x, data->props.y,
					0x000000);
			else
				mlx_put_pixel(data->img, data->props.x, data->props.y,
					get_color(iterations, data));
			data->props.x++;
		}
		data->props.y++;
	}
}

void	draw_fractal(t_mlx_data *data)
{
	if (ft_strcmp(data->fractal_type, "mandelbrot") == 0)
		mandelbrot(data);
	else if (ft_strcmp(data->fractal_type, "julia") == 0)
		julia(data);
	else if (ft_strcmp(data->fractal_type, "burning_ship") == 0)
		burning_ship(data);
	else
		ft_putstr("Fractal no reconocido\n");
}
