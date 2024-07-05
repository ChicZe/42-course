# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 10:41:26 by ciusca            #+#    #+#              #
#    Updated: 2024/02/21 15:08:07 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRCS = utils.c push_swap.c test.c list_functions.c list_functions2.c operations_a.c operations_b.c operations_ab.c LIS.c parsing.c sorting.c count_move.c sorting_utils.c move.c LIS_utils.c
BONUS_SRCS = checker.c matrix_functions.c operations_a.c operations_ab.c operations_b.c parsing.c list_functions.c list_functions2.c read_input.c

BONUS_OBJS = $(addprefix bonus_srcs/, ${BONUS_SRCS:.c=.o})
OBJS = $(addprefix src/, ${SRCS:.c=.o})

LIBFT_PATH = libft/
LIBFT_A = libft.a
LIBFT = libft/libft.a

GREEN = '\033[32m'
NONE = '\033[0m'
	
COMPILE = cc -Wall -Wextra -Werror -g

all: $(NAME)

%.o: %.c
		$(COMPILE) -I $(LIBFT_PATH) -c $< -o $@
$(NAME): $(OBJS)
		make bonus -C $(LIBFT_PATH)
		$(COMPILE) $(OBJS) $(LIBFT) -o $(NAME)
		@echo $(GREEN) "Compiled Successfully!" $(NONE)

bonus: all $(NAME_BONUS)

%.o: %.c
		$(COMPILE) -I $(LIBFT_PATH) -c $< -o $@
$(NAME_BONUS): $(BONUS_OBJS)
		make bonus -C $(LIBFT_PATH)
		$(COMPILE) $(BONUS_OBJS) $(LIBFT) -o $(NAME_BONUS)
		@echo $(GREEN) "Compiled Successfully!" $(NONE)
		
clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS) $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus