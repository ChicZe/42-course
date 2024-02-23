/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:43:37 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/23 14:19:50 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	close_function(char **input, t_lst **sa, t_lst **sb, int quit)
{
	free_matrix(input);
	if (ft_size(*sb) > 0)
		free_list(sb);
	if (ft_size(*sa) > 0)
		free_list(sa);
	exit(quit);
}

int	check_op(char *line, t_lst **stk_a, t_lst **stk_b)
{
	if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		pa(stk_a, stk_b);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		pb(stk_a, stk_b);
	else if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		sa(stk_a, 0);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		sb(stk_b, 0);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ra(stk_a, 0);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rb(stk_b, 0);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		rra(stk_a, 0);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		rrb(stk_b, 0);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(stk_a, stk_b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(stk_a, stk_b);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(stk_a, stk_b);
	else
		return (0);
	return (1);
}

int	read_input(t_lst **stk_a, t_lst **stk_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (check_op(line, stk_a, stk_b) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

void	init_check(char **input)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = create_stack(input);
	stack_b = NULL;
	if (read_input(&stack_a, &stack_b) == 0)
	{
		ft_printf("KO\n");
		close_function(input, &stack_a, &stack_b, 1);
	}
	if (check_sort(&stack_a) == 1 && ft_size(stack_b) == 0)
	{
		ft_printf("OK\n");
		close_function(input, &stack_a, &stack_b, 0);
	}
	ft_printf("KO\n");
	close_function(input, &stack_a, &stack_b, 1);
}
