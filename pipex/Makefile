# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 16:45:11 by ciusca            #+#    #+#              #
#    Updated: 2024/02/26 17:55:44 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c

OBJ = $(addprefix src/, $(SRC:.c=.o))

COMPILE = cc -Wall -Wextra -Werror

LIBFT_PATH = libft
LIBFT_A = libft.a
LIBFT = libft/libft.a

GREEN = '\033[32m'
NONE = '\033[0m'

all: $(NAME)

%.o: %.c
		$(COMPILE) -I $(LIBFT_PATH) -c $< -o $@

$(NAME): $(OBJ)
		make bonus -C $(LIBFT_PATH)
		$(COMPILE) $(OBJ) $(LIBFT) -o $(NAME)
		@echo $(GREEN) "Compiled Successfully" $(NONE)

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(OBJS) $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
