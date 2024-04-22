/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:00:28 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/04/19 16:36:58 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculate_iterations_burning_ship(t_fractal_vars vars)
{
	while (vars.iter < MAX_ITERATIONS)
	{
		vars.zx = fabs(vars.zx);
		vars.zy = fabs(vars.zy);
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

void	set_burning_ship_vars(t_mlx_data *data, int x, int y)
{
	data->vars.cx = data->vars.min_x + (double)x
		/ data->props.image_width * data->vars.zoom;
	data->vars.cy = data->vars.min_y + (double)y
		/ data->props.image_height * data->vars.zoom;
	data->vars.zx = 0;
	data->vars.zy = 0;
}

void	init_burning_ship(t_fractal_vars *vars)
{
	vars->min_x = -2.2;
	vars->min_y = -2;
	vars->zoom = 3.5;
}

void	burning_ship(t_mlx_data *data)
{
	draw_fractal_with_set_vars(data, set_burning_ship_vars);
}
