# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 13:51:20 by ciusca            #+#    #+#              #
#    Updated: 2024/01/11 21:05:34 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c map_parsing.c sprites_handle.c utils2.c controls.c utils.c handle_map.c enemies.c gui.c trim_matrix.c

OBJS = ${SRCS:.c=.o}

MLX_PATH = mlx/
MLX_A = libmlx.a
MLX = $(addprefix $(MLX_PATH), $(MLX_A))

MLX_INCLUDE = -lXext -lX11 -lm

LIBFT_PATH = libft/
LIBFT = libft/libft.a

COMPILE = cc -Wall -Wextra -Werror -g

NONE = '\033[0m'
GREEN = '\033[32m'
YELLOW = '\033[33m'
GRAY = '\033[2;37m'
CURSIVE = '\033[3m'

all: $(NAME)

$(NAME): $(OBJS)
		make -C mlx/
		make -C libft/
		$(COMPILE) $(OBJS) $(MLX) $(LIBFT) $(MLX_INCLUDE) -o $(NAME)
		@echo $(GREEN) "Compiled successfully! now just type ./so_long Maps/chose_a_map" $(NONE)

$(OBJS): $(SRCS)
		$(COMPILE) -c $(SRCS)

exe:
		make -C ./ clean
		@./$(NAME)

clean:
		@rm -rf $(OBJS)
		@make -C $(LIBFT_PATH) clean
		@make -C $(MLX_PATH) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIBFT_PATH) clean
		@make -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean