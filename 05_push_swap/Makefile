# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 18:53:26 by aorcha-m          #+#    #+#              #
#    Updated: 2024/03/25 16:29:10 by aorcha-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

SRCS        = sources/main.c \
			  $(wildcard sources/operations/*.c) \
			  $(wildcard sources/sorting/*.c) \
			  $(wildcard sources/utils/*.c)		

OBJS		= ${SRCS:.c=.o}

LIBFT		= ${LIBFT_PATH}/libft.a

LIBFT_PATH	= ./libft

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${OBJS}: %.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}: 
	@make -C ${LIBFT_PATH} all

clean:
	@${RM} ${OBJS} 
	@make -C ${LIBFT_PATH} clean

fclean: clean
	@${RM} ${NAME}
	@make -C ${LIBFT_PATH} fclean

re: fclean all

.PHONY: all clean fclean re
