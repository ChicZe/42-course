/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:11:04 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/11 20:18:55 by ciusca           ###   ########.fr       */
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
	int	*arr;

	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (-1);
	i = -1;
	while (++i < n)
	{
		if (moves[0][i] >= 0 && moves[1][i] >= 0)
			arr[i] = ft_max(moves[0][i], moves[1][i]);
		else if (moves[0][i] < 0 && moves[1][i] < 0)
			arr[i] = ft_min(moves[0][i], moves[1][i]) * -1;
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
	while (++i < end)
	{
		//check_swap(&stack_a, &stack_b);
		moves[0] = fill_arr(stack, stack_a, stack_b);
		moves[1] = count_b(stack_b);
		move_index = chose_move(moves, ft_size(stack_b));
		make_moves(&stack_a, &stack_b, move_index, moves);
		free(moves[0]);
		free(moves[1]);
		pa(&stack_a, &stack_b);
		/*ft_printf("stack a\n");
		ft_printf("stack b\n");*/
	}
	restore_stack(&stack_a);
	//print_list(stack_a);
}

t_lst	*push_lis(t_lst *stk_a, t_lst **stk_b, int *lis, int n)
{
	int		i;

	i = 0;
	// func();
	// if !func() return ;
	while (i < n)
	{
		if (lis[i] == stk_a->content)
		{
			ra(&stk_a, 1);
			i++;
		}
		else
			pb(&stk_a, stk_b);
		check_sort(&stk_a, stk_b);
		//stk_a = stk_a->next;
	}
	//&& stk_a->content > stk_a->next->content
	while (stk_a->content != lis[0])
	{
		if (stk_a->content < stk_a->next->content && check_sort(&stk_a, stk_b) == 1)
			break;
		pb(&stk_a, stk_b);
	}
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
	check_swap(&stack_a, &stack_b);
	get_arr(&stack_a, &lis_arr);
	stack_a = push_lis(stack_a, &stack_b, lis_arr.lis, lis_arr.n);
	ft_sorting(stack_a, stack_b, &stack);
}
