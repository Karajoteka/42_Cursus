/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:16:50 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/04/18 18:43:37 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_julia_vars(t_mlx_data *data, int x, int y)
{
	(void)x;
	(void)y;
	data->vars.zx = data->vars.min_x + (double)x / data->props.image_width
		* data->vars.zoom;
	data->vars.zy = data->vars.min_y + (double)y / data->props.image_height
		* data->vars.zoom;
	data->vars.cx = data->vars.julia_x;
	data->vars.cy = data->vars.julia_y;
}

void	init_julia(t_fractal_vars *vars, int option)
{
	vars->min_x = -1.2;
	vars->min_y = -1.3;
	vars->zoom = 2.5;
	if (option == 1)
	{
		vars->julia_x = 0.280;
		vars->julia_y = 0.010;
	}
	else if (option == 2)
	{
		vars->julia_x = 0.285;
		vars->julia_y = 0.012;
	}
	else if (option == 3)
	{
		vars->julia_x = 0.289;
		vars->julia_y = 0.014;
	}
	else
	{
		ft_putstr("Opción no reconocida. Opciones válidas 1, 2, 3\n");
		exit(1);
	}
}

void	julia(t_mlx_data *data)
{
	draw_fractal_with_set_vars(data, set_julia_vars);
}
