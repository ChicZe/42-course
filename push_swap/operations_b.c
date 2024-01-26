/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:30:05 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/26 15:41:50 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_lst **stk_b)
{
	t_lst	*temp;
	t_lst	*temp2;

	temp = *stk_b;
	temp2 = temp->next;
	*stk_b = temp2;
	temp->next = temp2->next;
	temp2->next = temp;
}

void	rb(t_lst **stk_b)
{
	t_lst	*temp;

	temp = *stk_b;
	temp = ft_newnode(temp->content);
	ft_add_back(stk_b, temp);
	*stk_b = remove_first(*stk_b);
}

void	rrb(t_lst **stk_b)
{
	t_lst	*temp;
	t_lst	*last;

	temp = *stk_b;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	ft_add_front(stk_b, temp);
}