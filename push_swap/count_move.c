/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:46:19 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/08 17:33:05 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bigger(int target, int *arr, int n)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (++i < n)
		if (arr[i] > target)
			count++;
	return (count);
}

int	find_min(int *arr, int n)
{
	int	min;
	int i;

	
	i = -1;
	if (n == 0)
		return (-1);
	min = arr[0];
	while (++i < n)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return (min);
}

int	find_bigger(int n, int *arr, int target)
{
	int	i;
	int *bigger;	
	int	j;
	int min;

	bigger = malloc(sizeof(int) * count_bigger(target, arr, n));
	j = 0;
	i = -1;
	while (++i < n)
		if (arr[i] > target)
		{
			bigger[j] = arr[i];
			j++;
		}
	i = -1;
	min = bigger[0];
	while (++i < j)
	{
		if (bigger[i] < min)
			min = bigger[i];
	}
	if (j == 0)
		min = find_min(arr, n);
	//ft_printf("min = %d\n", min);
	return (min);
}

int	find_pos(int n, int target)
{
	int	i;
	int	count;
	int	mid;

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
	return (0);
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
	int	bigger;
	int	j;
	
	count_a = malloc(sizeof(int) * stack->b_len);
	if (!count_a)
		return (NULL);
	i = -1;
	while (++i < stack->b_len)
	{
		j = -1;
		bigger = find_bigger(stack->a_len, sa, sb[i]);
		while (++j < stack->a_len)
			if (sa[j] == bigger)
				break ;
		if (j == stack->a_len)
			j = 0;
		else
			j = find_pos(stack->a_len, j);
		count_a[i] = j;
	}
	//for (int i = 0; i < stack->b_len; i++)
		//ft_printf("count a = %d\n", count_a[i]);
	return (count_a);
}
