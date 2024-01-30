/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:46:19 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/29 16:38:28 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(int n, int target)
{
	int	mid;
	int	i;
	int	count;

	count = 1;
	i = -1;
	mid = n / 2;
	while (++i < mid)
		if (i == target)
			return (i);
	i = n;
	while (--i >= mid)
	{
		if (i == target)
			return (count * -1);
		count++;
	}
	return (target);
}

int	*count_b(t_lst *stack_b)
{
	int	*move_b;
	int	len;
	int	middle;
	int	i;
	int	count;

	count = 1;
	i = -1;
	len = ft_size(stack_b);
	move_b = malloc(sizeof(int) * len);
	if (!move_b)
		return (NULL);
	middle = len / 2;
	while (++i < middle)
		move_b[i] = i;
	i = len;
	while (--i >= middle)
	{
		move_b[i] = count * -1;
		count++;		
	}
	return (move_b);
}

int	*count_a(t_arr *stack, int *sa, int *sb)
{
	int	*count_a;
	int	i;
	int	j;
	
	count_a = malloc(sizeof(int) * stack->b_len);
	if (!count_a)
		return (NULL);
	i = -1;
	while (++i < stack->b_len)
	{
		j = -1;
		while (++j < stack->a_len)
			if (sb[i] < sa[j])
			{
				j = find_pos(stack->a_len, j);
				count_a[i] = j;
				break;
			}
			else if (j + 1 == stack->a_len)
				count_a[i] = 0;
	}
	return (count_a);
}
