/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:36:09 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/08 12:57:15 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_pos(int **moves, int index, t_lst **sa, t_lst **sb)
{
	int	i;
	int a;
	int	b;
	int min;

	ft_printf("--- pos pos ---\n");
	i = -1;
	a = moves[0][index];
	b = moves[1][index];
	min = ft_min(a, b);
	if (min > 0)
		while (++i < min)
			rr(sa, sb);
	while (a - min > 0)
	{
		ra(sa, 1);
		a--;
	}
	while (b - min > 0)
	{
		rb(sb, 1);
		b--;
	}
	ft_printf("--- end ---\n");
}

void	neg_pos(int **moves, int index, t_lst **sa, t_lst **sb)
{
	int	a;
	int	b;

	ft_printf("--- neg pos ---\n");
	a = moves[0][index];
	b = moves[1][index];
	//ft_printf("a = %d -- b = %d\n", a, b);
	if (a < 0)
	{
		a *= -1;
		while (--a >= 0)
			rra(sa, 1);
		while (--b >= 0)
			rb(sb, 1);
	}
	else if (b < 0)
	{
		b *= -1;
		while (--b >= 0)
			rrb(sb, 1);
		//ft_printf("b = %d\n", b);
		while (--a >= 0)
			ra(sa, 1);
	}
	ft_printf("--- end ---\n");
}

void	neg_neg(int **moves, int index, t_lst **sa, t_lst **sb)
{
	int	i;
	int a;
	int	b;
	int max;

	ft_printf("--- neg neg ---\n");
	i = 1;
	a = moves[0][index];
	b = moves[1][index];
	//ft_printf(" a = %d b = %d\n", a, b);
	max = ft_max(a, b);
	while (--i > max)
		rrr(sa, sb);
	while (a - max < 0)
	{
		rra(sa, 1);
		a++;
	}
	while (b - max < 0)
	{
		rrb(sb, 1);
		b++;
	}
	ft_printf("--- end ---\n");
}

void	restore_stack(t_lst **sa)
{
	int		size;
	t_lst	*temp;
	int		count;
	int		i;

	ft_printf("--- restore stack ---\n");
	i = 0;
	count = 1;
	temp = *sa;
	size = ft_size(*sa);
	while (temp->next != NULL)
	{
		if (temp->content < temp->next->content)
			count++;
		else
			break;
		temp = temp->next;
		i++;
	}
	ft_printf("count = %d\n", count);
	ft_printf("size = %d\n", size - count);
	if (i <= size / 2)
	{
		i = -1;
		while (++i < count)
			ra(sa, 1);
	}
	else if (size - count > size / 2)
	{
		i = size;
		while (--i > size / 2)
			rra(sa, 1);
	}
	ft_printf("--- end ---\n");
}
