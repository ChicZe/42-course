/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:36:09 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/30 16:13:21 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_pos(int **moves, int index, t_lst *sa, t_lst *sb)
{
	int	i;
	int a;
	int	b;
	int min;

	i = -1;
	a = moves[0][index];
	b = moves[1][index];
	min = ft_min(a, b);
	if (min > 0)
		while (++i < min)
			rr(&sa, &sb);
	while (a - min > 0)
	{
		ra(&sa, 1);
		a -= min;
	}
	while (b - min > 0)
	{
		rb(&sb, 1);
		b -= min;
	}
}

void	neg_pos(int **moves, int index, t_lst *sa, t_lst *sb)
{
	int	a;
	int	b;

	a = moves[0][index];
	b = moves[1][index];
	if (a < 0)
	{
		a--;
		while (++a * -1 < 0)
			rra(&sa, 1);
		b++;
		while (--b > 0)
			rb(&sb, 1);
	}
	else if (b < 0)
	{
		b--;
		while (++b * -1 < 0)
			rrb(&sa, 1);
		a++;
		while (--a > 0)
			ra(&sb, 1);
	}
}

void	neg_neg(int **moves, int index, t_lst *sa, t_lst *sb)
{
	int	i;
	int a;
	int	b;
	int max;

	i = 1;
	a = moves[0][index];
	b = moves[1][index];
	max = ft_max(a, b);
	while (--i > max)
		rrr(&sa, &sb);
	while (a + max > 0)
	{
		ra(&sa, 1);
		a += max;
	}
	while (b + max > 0)
	{
		rb(&sb, 1);
		b += max;
	}
}

void	restore_stack(t_lst **sa, t_lst **sb)
{
	
}