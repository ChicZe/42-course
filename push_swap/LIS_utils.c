/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:47:15 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/13 19:32:49 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_swap(t_lst **stk_a, t_lst **stk_b)
{
	t_lst	*temp;
	t_lst	*last;

	last = ft_last(*stk_a);
	temp = *stk_a;
	if (last->content < temp->content && last->content < temp->next->content)
	{
		if (temp->content > temp->next->content)
			sa(stk_a, 1);
		rra(stk_a, 1);
	}
	else if (last->content > temp->content && temp->content > temp->next->content)
		sa(stk_a, 1);
	else if (temp->content < temp->next->content && temp->next->content > last->content)
	{
		rra(stk_a, 1);
		sa(stk_a, 1);
	}
	else if (last->content < temp->content && temp->content > temp->next->content)
		ra(stk_a, 1);
	else if (temp->content > temp->next->content)
		sa(stk_a, 1);
	if (check_sort(stk_a) == 1 && ft_size(*stk_b) == 0)
		return (0);
	return (1);
}
