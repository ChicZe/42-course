/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:11:04 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/30 17:52:08 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_moves(t_lst *sa, t_lst *sb, int index, int **moves)
{
	int	i;

	i = -1;
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

void	ft_sorting(t_lst **stack_a, t_lst **stack_b, t_arr *stack)
{
	int	*moves[2];
	int	i;
	int	move_index;
	int	end;

	end = ft_size(*stack_b);
	i = -1;
	while (++i < end)
	{
		moves[0] = fill_arr(stack, *stack_a, *stack_b);
		moves[1] = count_b(*stack_b);
		move_index = chose_move(moves, ft_size(*stack_b));
		ft_printf("\n size = %d\n", ft_size(*stack_a));
		ft_printf("\n\n --- stack a ---\n");
			print_list(*stack_a);
		//make_moves(*stack_a, *stack_b, move_index, moves);
		free(moves[0]);
		free(moves[1]);
		pa(stack_a, stack_b);
		restore_stack(stack_a, stack_b);
	}
}

void	push_lis(t_lst **stk_a, t_lst **stk_b, int *lis, int n)
{
	int		i;
	t_lst	*temp;

	temp = *stk_a;
	i = 0;
	while (i < n)
	{
		if (lis[i] == temp->content)
		{
			ra(&temp, 1);
			i++;
		}
		else
			pb(&temp, stk_b);
	}
	while (temp->content != lis[0])
		pb(&temp, stk_b);
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
	push_lis(&stack_a, &stack_b, lis_arr.lis, lis_arr.n);
	ft_sorting(&stack_a, &stack_b, &stack);
	//move_b = count_b(stack_b);
	//move_a = fill_arr(&stack, stack_a, stack_b);
	//print_list(stack_a);
}
