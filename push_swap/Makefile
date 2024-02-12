# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 10:41:26 by ciusca            #+#    #+#              #
#    Updated: 2024/02/11 17:53:02 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c test.c list_functions.c list_functions2.c operations_a.c operations_b.c operations_ab.c LIS.c parsing.c sorting.c count_move.c sorting_utils.c move.c LIS_utils.c
OBJS = ${SRCS:.c=.o}

LIBFT_PATH = libft/
LIBFT_A = libft.a
LIBFT = libft/libft.a

GREEN = '\033[32m'
NONE = '\033[0m'
	
COMPILE = cc -Wall -Wextra -Werror -g

all: $(NAME)

%.o: %.c
		@echo building $@
		$(COMPILE) -I$(LIBFT_PATH) -c $< -o $@
$(NAME): $(OBJS)
		make bonus -C $(LIBFT_PATH)
		$(COMPILE) $(OBJS) $(LIBFT) -o $(NAME)
		@echo $(GREEN) "Compiled Successfully!" $(NONE)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME) $(OBJS)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re