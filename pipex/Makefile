# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 16:45:11 by ciusca            #+#    #+#              #
#    Updated: 2024/02/29 18:21:53 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c parsing.c check_execve.c

OBJ = $(addprefix src/, $(SRC:.c=.o))

COMPILE = cc -Wall -Wextra -Werror -g

LIBFT_PATH = libft
LIBFT_A = libft.a
LIBFT = libft/libft.a

RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
MAGENTA = "\033[1;35m"
CYAN = "\033[1;36m"
WHITE = "\033[1;37m"
NONE = '\033[0m'

all: $(NAME)

%.o: %.c
		$(COMPILE) -I $(LIBFT_PATH) -c $< -o $@

$(NAME): $(OBJ)
		make bonus -C $(LIBFT_PATH)
		$(COMPILE) $(OBJ) $(LIBFT) -o $(NAME)
		@echo $(RED) "______ ___________ _______   __ " $(NONE)
		@echo $(GREEN) "| ___ \_   _| ___ \  ___\ \ / / " $(NONE)
		@echo $(YELLOW) "| |_/ / | | | |_/ / |__  \ V /  " $(NONE)
		@echo $(BLUE) "|  __/  | | |  __/|  __| /   \  " $(NONE)
		@echo $(MAGENTA) "| |    _| |_| |   | |___/ / \ \ " $(NONE)
		@echo $(CYAN) "\_|    \___/\_|   \____/\/   \/ " $(NONE)
		@echo $(WHITE) "\n\n\nHow it works:" $(YELLOW) "./pipex infile cmd cmd2 outfile \n\n\n" $(NONE)

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(OBJS) $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re

.SILENT:
