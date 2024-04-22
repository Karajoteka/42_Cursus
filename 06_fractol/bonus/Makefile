# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 16:37:43 by aorcha-m          #+#    #+#              #
#    Updated: 2024/04/19 15:36:55 by aorcha-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol

NAME_BONUS	= fractol_bonus

SRCS_FRACTOL  = sources/main.c \
				sources/colors.c \
				sources/events.c \
				sources/mandelbrot.c \
				sources/julia.c \
				sources/fractals.c

BONUS_FRACTOL = bonus/main_bonus.c \
				bonus/colors_bonus.c \
				bonus/events_bonus.c \
				bonus/mandelbrot_bonus.c \
				bonus/julia_bonus.c \
				bonus/fractals_bonus.c \
				bonus/burning_ship_bonus.c		

OBJS_FRACTOL	= ${SRCS_FRACTOL:.c=.o}

OBJS_BONUS_FRACTOL	= ${BONUS_FRACTOL:.c=.o}

MLX			= ${MLX_PATH}/libmlx42.a

MLX_PATH	= ./MLX42

LIBFT		= ${LIBFT_PATH}/libft.a

LIBFT_PATH	= ./libft

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

FRAMEWORK	= -framework Cocoa -framework OpenGL -framework IOKit

GLFW		= -Iinclude -lglfw -L"/Users/aorcha-m/.brew/opt/glfw/lib/"

all: ${NAME}

${NAME}: ${OBJS_FRACTOL} ${LIBFT} ${MLX}
	@${CC} ${CFLAGS} ${OBJS_FRACTOL} ${LIBFT} ${MLX} ${GLFW} ${FRAMEWORK} -o ${NAME}

${NAME_BONUS}: ${OBJS_BONUS_FRACTOL} ${LIBFT} ${MLX}
	@${CC} ${CFLAGS} ${OBJS_BONUS_FRACTOL} ${LIBFT} ${MLX} ${GLFW} ${FRAMEWORK} -o ${NAME_BONUS} 

${OBJS_FRACTOL}: %.o: %.c
	@${CC} ${CFLAGS} -I ${LIBFT_PATH} -c $< -o $@

${LIBFT}: 
	@make -C ${LIBFT_PATH} all

${MLX}: 
	@make -C ${MLX_PATH} all

bonus: ${NAME_BONUS}

clean:
	@${RM} ${OBJS_FRACTOL} ${OBJS_BONUS_FRACTOL}
	@make -C ${LIBFT_PATH} clean
	@make -C ${MLX_PATH} clean

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}
	@make -C ${LIBFT_PATH} fclean
	@make -C ${MLX_PATH} fclean

re: fclean all

.PHONY: all clean fclean re
