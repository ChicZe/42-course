/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:37:06 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/09 19:38:37 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_arr(t_arr *stack, t_lst *stack_a, t_lst *stack_b)
{
	int	*sa;
	int	*sb;
	int	*count_moves;

	stack->a_len = ft_size(stack_a);
	sa = list_to_array(stack_a);
	if (!sa)
		return (NULL);
	stack->b_len = ft_size(stack_b);
	sb = list_to_array(stack_b);
	if (!sb)
		return (NULL);
	count_moves = count_a(stack, sa, sb);
	free(sa);
	free(sb);
	return (count_moves);
}

void	print_list(t_lst *list)
{
	t_lst	*temp;
	int		i;

	i = 0;
	temp = list;
	while (temp)
	{
		ft_printf("data = %d\n", temp->content);
		temp = temp->next;
		i++;
	}
	ft_printf("stack n = %d\n", i);
}

int	main(int argc, char **argv)
{
	char	**input;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		input = ft_split(argv[1], 32);
		input = matrix_join(argv[0], input);
	}
	else
		input = argv;
	argc = matrix_len(input);
	ft_printf("argc = %d\n", argc);
	check_invalid(input, argc);
	init_sort(input);
}
