# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 15:36:15 by agu               #+#    #+#              #
#    Updated: 2023/12/14 19:36:57 by aorcha-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

SRCS        = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c \
			  ft_puthex.c ft_puthexptr.c

OBJS        = ${SRCS:.c=.o}

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -c ${SRCS}
	ar crs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

