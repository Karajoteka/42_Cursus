/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:55:01 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/04/22 15:50:24 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <ctype.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_ITERATIONS 100
# define MOVE_FACTOR 0.1

# define KEY_UP 264
# define KEY_DOWN 265
# define ESC 53
# define C 67

typedef struct s_image_properties
{
	int					x;
	int					y;
	int					window_width;
	int					window_height;
	int					image_width;
	int					image_height;
	int					start_x;
	int					start_y;
}						t_image_properties;

typedef struct s_fractal_vars
{
	double				zx;
	double				zy;
	double				cx;
	double				cy;
	double				zx2;
	double				zy2;
	int					iter;
	double				min_x;
	double				min_y;
	double				zoom;
	double				mouse_x;
	double				mouse_y;
	double				julia_x;
	double				julia_y;
}						t_fractal_vars;

typedef struct s_mlx_data
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	t_image_properties	props;
	t_fractal_vars		vars;
	char				fractal_type[20];
	int					color_mode;
	int					key_is_pressed;
}						t_mlx_data;

int						get_color(int iterations, t_mlx_data *data);

int						calculate_iterations(t_fractal_vars vars);
void					draw_fractal_with_set_vars(t_mlx_data *data,
							void (*set_vars)(t_mlx_data *, int, int));
void					draw_fractal(t_mlx_data *data);

void					set_mandelbrot_vars(t_mlx_data *data, int x, int y);
void					init_mandelbrot(t_fractal_vars *vars);
void					mandelbrot(t_mlx_data *data);

void					set_julia_vars(t_mlx_data *data, int x, int y);
void					init_julia(t_fractal_vars *vars, int option);
void					julia(t_mlx_data *data);

int						calculate_iterations_burning_ship(t_fractal_vars vars);
void					set_burning_ship_vars(t_mlx_data *data, int x, int y);
void					init_burning_ship(t_fractal_vars *vars);
void					burning_ship(t_mlx_data *data);

void					update_zoom(t_mlx_data *data, double zoom_factor);
void					handle_key(struct mlx_key_data key_data, void *param);
void					handle_scroll(double x, double y, void *param);
void					handle_mouse_move(double x, double y, void *param);

#endif
