/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:47:15 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/20 19:58:59 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_swap2(t_lst **stack_a)
{
	t_lst	*tmp;

	tmp = *stack_a;
	if (tmp->content < tmp->next->content
		&& tmp->next->content > ft_last(*stack_a)->content)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (ft_last(*stack_a)->content < tmp->content
		&& tmp->content > tmp->next->content)
		ra(stack_a, 1);
	else if (tmp->content > tmp->next->content
		&& tmp->content < tmp->next->next->content
		&& tmp->content < tmp->next->next->content)
		sa(stack_a, 1);
}

int	check_swap(t_lst **stack_a, t_lst **stk_b)
{
	t_lst	*tmp;

	tmp = *stack_a;
	if (ft_last(*stack_a)->content < tmp->content
		&& ft_last(*stack_a)->content < tmp->next->content)
	{
		if (tmp->content > tmp->next->content
			&& tmp->content < tmp->next->next->content)
			sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (ft_last(*stack_a)->content > tmp->content
		&& tmp->content > tmp->next->content
		&& tmp->content < tmp->next->next->content)
		sa(stack_a, 1);
	else
		check_swap2(stack_a);
	if (check_sort(stack_a) == 1 && ft_size(*stk_b) == 0)
		return (0);
	return (1);
}
