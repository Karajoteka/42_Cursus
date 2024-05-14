# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 18:53:26 by aorcha-m          #+#    #+#              #
#    Updated: 2024/05/13 15:49:54 by aorcha-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES  	= sources/server.c sources/client.c

OBJECTS		= ${SOURCES:.c=.o}

LIBFT		= ${LIBFT_PATH}/libft.a

LIBFT_PATH	= ./libft

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

all: server client

bonus: server client

server: sources/server.o ${LIBFT}
	@${CC} ${CFLAGS} sources/server.o ${LIBFT} -o server

client: sources/client.o ${LIBFT}
	@${CC} ${CFLAGS} sources/client.o ${LIBFT} -o client

${OBJECTS}: %.o: %.c
	@${CC} ${CFLAGS} -I ${LIBFT_PATH} -c $< -o $@

${LIBFT}: 
	@make -C ${LIBFT_PATH} all

clean:
	@${RM} ${OBJECTS} 
	@make -C ${LIBFT_PATH} clean

fclean: clean
	@${RM} ${OBJECTS} server client
	@make -C ${LIBFT_PATH} fclean

re: fclean all

.PHONY: all clean fclean re bonus
