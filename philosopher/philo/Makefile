# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 15:52:36 by ciusca            #+#    #+#              #
#    Updated: 2024/04/25 11:19:31 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c routine.c parsing.c philo_actions.c utils.c

OBJ = $(addprefix src/, $(SRC:.c=.o))

COMPILE = cc -Wall -Wextra -Werror -pthread

LIBFT_PATH = libft
LIBFT_A = libft.a
LIBFT = libft/libft.a

RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
MAGENTA = "\033[1;35m"void	philo_eat(t_philo *philo)
CYAN = "\033[1;36m"
WHITE = "\033[1;37m"
NONE = '\033[0m'

all: $(NAME)

%.o: %.c
		$(COMPILE) -I $(LIBFT_PATH) -c $< -o $@

$(NAME): $(OBJ)
		make bonus -C $(LIBFT_PATH)
		$(COMPILE) $(OBJ) $(LIBFT) -o $(NAME)                               
		@echo $(CYAN) " _______ ____  ____ _____ _____      ___  " $(NONE)
		@echo $(WHITE) "|_   __ \_   ||   _|_   _|_   _|   .'   .  " $(NONE)
		@echo $(CYAN) "  | |__) || |__| |   | |   | |    /  .-.  \  " $(NONE)
		@echo $(CYAN) "  |  ___/ |  __  |   | |   | |   _| |   | |  " $(NONE)
		@echo $(WHITE) " _| |_   _| |  | |_ _| |_ _| |__/   -'  " $(NONE)
		@echo $(CYAN) "|_____| |____||____|_____|________| .___.'" $(NONE)
		@echo "\n\n"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(BONUS_OBJS)
	@make -C $(LIBFT_PATH) clean
	@echo $(GREEN) "\nCLEAN COMPLETED\n" $(NONE)

fclean: clean
	@rm -rf $(OBJS) $(BONUS_OBJS) $(NAME) $(NAME_B)
	@make -C $(LIBFT_PATH) fclean
	
re: fclean all

.PHONY: all clean fclean re

.SILENT:
