# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <cristianiusca13@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 18:04:05 by ciusca            #+#    #+#              #
#    Updated: 2023/11/10 16:15:26 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_itoa.c ft_putchar.c ft_putnbr.c ft_putstr.c hexa_converter.c printf_hex.c ft_strlen.c ft_strlcpy.c ft_printf_uns.c ft_toupper.c
OBJS = ${SRCS:.c=.o}
HEADER = ft_printf.h

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o: %.c ${HEADER}
	cc -Wall -Wextra -Werror -c $?

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean