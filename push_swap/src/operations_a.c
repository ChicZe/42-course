/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:31:01 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/20 19:59:14 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	remove_node(t_lst *node)
{
	free(node);
	node = NULL;
}

t_lst	*remove_first(t_lst *stk_a)
{
	t_lst	*head;

	head = stk_a;
	stk_a = stk_a->next;
	free(head);
	head = NULL;
	return (stk_a);
}

void	sa(t_lst **stk_a, int flag)
{
	t_lst	*temp;
	t_lst	*temp2;

	temp = *stk_a;
	temp2 = temp->next;
	*stk_a = temp2;
	temp->next = temp2->next;
	temp2->next = temp;
	if (flag == 1)
		ft_printf("sa\n");
}

void	ra(t_lst **stk_a, int flag)
{
	t_lst	*temp;

	if (ft_size(*stk_a) < 2)
		return ;
	temp = *stk_a;
	temp = ft_newnode(temp->content);
	ft_add_back(stk_a, temp);
	*stk_a = remove_first(*stk_a);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rra(t_lst **stk_a, int flag)
{
	t_lst	*temp;
	t_lst	*last;
	t_lst	*new;

	if (ft_size(*stk_a) < 2)
		return ;
	temp = *stk_a;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	new = ft_newnode(temp->content);
	free(last->next);
	last->next = NULL;
	ft_add_front(stk_a, new);
	if (flag == 1)
		ft_printf("rra\n");
}
