/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:14:35 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/04/17 19:25:46 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_mandelbrot_vars(t_mlx_data *data, int x, int y)
{
	(void)x;
	(void)y;
	data->vars.cx = data->vars.min_x + (double)data->props.x
		/ data->props.image_width * data->vars.zoom;
	data->vars.cy = data->vars.min_y + (double)data->props.y
		/ data->props.image_height * data->vars.zoom;
	data->vars.zx = 0;
	data->vars.zy = 0;
}

void	init_mandelbrot(t_fractal_vars *vars)
{
	vars->min_x = -2.2;
	vars->min_y = -1.8;
	vars->zoom = 3.5;
}

void	mandelbrot(t_mlx_data *data)
{
	draw_fractal_with_set_vars(data, set_mandelbrot_vars);
}
