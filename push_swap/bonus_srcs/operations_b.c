/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:30:05 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/23 14:08:29 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sb(t_lst **stk_b, int flag)
{
	t_lst	*temp;
	t_lst	*temp2;

	if (ft_size(*stk_b) < 2)
		return ;
	temp = *stk_b;
	temp2 = temp->next;
	*stk_b = temp2;
	temp->next = temp2->next;
	temp2->next = temp;
	if (flag == 1)
		ft_printf("sb\n");
}

void	rb(t_lst **stk_b, int flag)
{
	t_lst	*temp;

	if (ft_size(*stk_b) < 2)
		return ;
	temp = *stk_b;
	temp = ft_newnode(temp->content);
	ft_add_back(stk_b, temp);
	*stk_b = remove_first(*stk_b);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rrb(t_lst **stk_b, int flag)
{
	t_lst	*temp;
	t_lst	*last;

	if (ft_size(*stk_b) < 2)
		return ;
	temp = *stk_b;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	ft_add_front(stk_b, temp);
	if (flag == 1)
		ft_printf("rrb\n");
}
