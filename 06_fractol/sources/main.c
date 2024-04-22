/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:53:31 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/04/19 17:22:37 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

mlx_image_t	*create_image(mlx_t **mlx, t_image_properties *props)
{
	props->window_width = 1000;
	props->window_height = 1000;
	props->image_width = 1000;
	props->image_height = 1000;
	*mlx = mlx_init(props->window_width, props->window_height, "Fractol",
			false);
	return (mlx_new_image(*mlx, props->image_width, props->image_height));
}

void	draw_and_display_image(t_mlx_data *data)
{
	draw_fractal(data);
	data->props.start_x = (data->props.window_width - data->props.image_width)
		/ 2;
	data->props.start_y = (data->props.window_height - data->props.image_height)
		/ 2;
	mlx_image_to_window(data->mlx, data->img, data->props.start_y,
		data->props.start_x);
	mlx_loop(data->mlx);
}

int	create_and_draw_image(char *fractal_type, t_fractal_vars *vars)
{
	t_image_properties	props;
	t_mlx_data			data;

	data.vars = *vars;
	ft_strlcpy(data.fractal_type, fractal_type, sizeof(data.fractal_type));
	data.img = create_image(&data.mlx, &props);
	data.props = props;
	data.color_mode = 0;
	mlx_key_hook(data.mlx, handle_key, &data);
	mlx_scroll_hook(data.mlx, handle_scroll, &data);
	mlx_cursor_hook(data.mlx, handle_mouse_move, &data);
	draw_and_display_image(&data);
	return (0);
}

int	check_input_and_init_vars(int argc, char **argv, t_fractal_vars *vars)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		init_mandelbrot(vars);
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 3)
		{
			ft_putstr("Uso: ./fractol julia [1/2/3]\n");
			return (1);
		}
		init_julia(vars, ft_atoi(argv[2]));
	}
	else
	{
		ft_putstr("Fractal no reconocido. Opciones válidas: mandelbrot, "
			"julia\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal_vars	vars;

	if (argc < 2)
	{
		ft_putstr("Uso: ./fractol [mandelbrot/julia] [1/2/3 para julia]\n");
		return (1);
	}
	if (check_input_and_init_vars(argc, argv, &vars))
		return (1);
	create_and_draw_image(argv[1], &vars);
	return (0);
}
