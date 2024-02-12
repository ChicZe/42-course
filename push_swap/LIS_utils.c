/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:47:15 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/11 19:03:57 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_swap(t_lst **stk_a, t_lst **stk_b)
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
	//else if (temp->content > temp->next->content && temp->content < temp->next->next->content)
	//	sa(stk_a, 1);
	else if (temp->content < temp->next->content && temp->next->content > last->content)
	{
		rra(stk_a, 1);
		sa(stk_a, 1);
	}
	else if (last->content < temp->content && temp->content > temp->next->content)
		ra(stk_a, 1);
	else if (temp->content > temp->next->content)
		sa(stk_a, 1);
	check_sort(stk_a, stk_b);
}
