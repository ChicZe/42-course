/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:11:04 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/08 12:31:14 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_moves(t_lst **sa, t_lst **sb, int index, int **moves)
{
	if (moves[0][index] >= 0 && moves[1][index] >= 0)
		pos_pos(moves, index, sa, sb);
	else if (moves[0][index] < 0 && moves[1][index] >= 0)
		neg_pos(moves, index, sa, sb);
	else if (moves[0][index] >= 0 && moves[1][index] < 0)
		neg_pos(moves, index, sa, sb);
	else if (moves[0][index] < 0 && moves[1][index] < 0)
		neg_neg(moves, index, sa, sb);
}

int	chose_move(int **moves, int n)
{
	int	i;
	int	arr[n];

	i = -1;
	while (++i < n)
	{
		if (moves[0][i] >= 0 && moves[1][i] >= 0)
			arr[i] = ft_max(moves[0][i], moves[1][i]);
		else if (moves[0][i] < 0 && moves[1][i] < 0)
			arr[i] = ft_min(moves[0][i], moves[1][i]);
		else if (moves[0][i] < 0 && moves[1][i] >= 0)
			arr[i] = (moves[0][i] * -1) + moves[1][i];
		else if (moves[0][i] >= 0 && moves[1][i] < 0)
			arr[i] = moves[0][i] + (moves[1][i] * -1);
	}
	i = find_smallest(arr, n);
	return (i);
}

void	ft_sorting(t_lst *stack_a, t_lst *stack_b, t_arr *stack)
{
	int	*moves[2];
	int	i;
	int	move_index;
	int	end;

	end = ft_size(stack_b);
	i = -1;
	while (++i < end -1)
	{
		ft_printf("-- first stack a ---\n");
		print_list(stack_a);
		ft_printf("-- stack b ---\n");
		print_list(stack_b);
		moves[0] = fill_arr(stack, stack_a, stack_b);
		moves[1] = count_b(stack_b);
		move_index = chose_move(moves, ft_size(stack_b));
		//ft_printf("index = %d move a = %d, move b = %d\n", move_index, moves[0][0], moves[1][0]);
		make_moves(&stack_a, &stack_b, move_index, moves);
		//free(moves[0]);
		//free(moves[1]);
		ft_printf("--  move stack a ---\n");
		print_list(stack_a);
		pa(&stack_a, &stack_b);
		ft_printf("-- push stack a ---\n");
		print_list(stack_a);
		//restore_stack(&stack_a);
		ft_printf("-- final stack a ---\n");
		print_list(stack_a);
	}
	printf("\n--- stack a ---\n");
	print_list(stack_a);
}

t_lst	*push_lis(t_lst *stk_a, t_lst **stk_b, int *lis, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (lis[i] == stk_a->content)
		{
			ra(&stk_a, 1);
			i++;
		}
		else
			pb(&stk_a, stk_b);
	}
	while (stk_a->content != lis[0])
		pb(&stk_a, stk_b);
	return (stk_a);
}

void	init_sort(char **input)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lis	lis_arr;
	t_arr	stack;

	stack_b = NULL;
	stack_a = create_stack(input);
	get_arr(&stack_a, &lis_arr);
	stack_a = push_lis(stack_a, &stack_b, lis_arr.lis, lis_arr.n);
	ft_sorting(stack_a, stack_b, &stack);
	//move_b = count_b(stack_b);
	//move_a = fill_arr(&stack, stack_a, stack_b);
	//print_list(stack_a);
}
