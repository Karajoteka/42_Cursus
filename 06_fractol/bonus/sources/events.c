/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:51:14 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/04/19 17:58:30 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	update_zoom(t_mlx_data *data, double zoom_factor)
{
	double	fractal_x;
	double	fractal_y;

	fractal_x = data->vars.min_x + data->vars.mouse_x / data->props.image_height
		* data->vars.zoom;
	fractal_y = data->vars.min_y + data->vars.mouse_y / data->props.image_width
		* data->vars.zoom;
	data->vars.zoom *= zoom_factor;
	data->vars.min_x = fractal_x - data->vars.mouse_x / data->props.image_height
		* data->vars.zoom;
	data->vars.min_y = fractal_y - data->vars.mouse_y / data->props.image_width
		* data->vars.zoom;
}

void	handle_key(struct mlx_key_data key_data, void *param)
{
	t_mlx_data	*data;
	int			key;
	double		move_factor;

	data = (t_mlx_data *)param;
	key = key_data.key;
	move_factor = 0.1 * data->vars.zoom;
	if (key_data.action == 0)
	{
		if (key == KEY_UP)
			update_zoom(data, 1.1);
		else if (key == KEY_DOWN)
			update_zoom(data, 0.9);
		else if (key == 256)
		{
			mlx_terminate(data->mlx);
			exit(0);
		}
		else if (key == C)
			data->color_mode = (data->color_mode + 1) % 2;
		draw_fractal(data);
	}
}

void	handle_scroll(double x, double y, void *param)
{
	t_mlx_data	*data;

	(void)x;
	data = (t_mlx_data *)param;
	if (y > 0)
		update_zoom(data, 1.1);
	else
		update_zoom(data, 0.9);
	draw_fractal(data);
}

void	handle_mouse_move(double x, double y, void *param)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)param;
	data->vars.mouse_x = x;
	data->vars.mouse_y = y;
	draw_fractal(data);
}
