/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:31:34 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/23 18:37:01 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_lst **stk_a, t_lst **stk_b)
{
	sa(stk_a);
	sb(stk_b);
	ft_printf("ss\n");
}

void	rr(t_lst **stk_a, t_lst **stk_b)
{
	ra(stk_a);
	rb(stk_b);
	ft_printf("rr\n");
}

void	rrr(t_lst **stk_a, t_lst **stk_b)
{
	rra(stk_a);
	rrb(stk_b);
	printf("rrr\n");
}

void	pa(t_lst **stk_a, t_lst **stk_b)
{
	t_lst	*temp;

	temp = *stk_b;
	temp = ft_newnode(temp->content);
	ft_add_front(stk_a, temp);
	*stk_b = remove_first(*stk_b);
	ft_printf("pa\n");
}

void	pb(t_lst **stk_a, t_lst **stk_b)
{
	t_lst	*temp;

	temp = *stk_a;
	temp = ft_newnode(temp->content);
	ft_add_front(stk_b, temp);
	*stk_a = remove_first(*stk_a);
	ft_printf("pb\n");
}
