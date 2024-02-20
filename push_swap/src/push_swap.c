/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:37:06 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/20 19:59:31 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	main(int argc, char **argv)
{
	char	**input;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		input = ft_split(argv[1], 32);
		if (!input)
			return (1);
	}
	else
		input = ft_matrix_dup(&argv[1]);
	argc = matrix_len(input);
	check_invalid(input, argc);
	init_sort(input);
}
