/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:31:34 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/23 12:57:32 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ss(t_lst **stk_a, t_lst **stk_b)
{
	sa(stk_a, 0);
	sb(stk_b, 0);
}

void	rr(t_lst **stk_a, t_lst **stk_b)
{
	ra(stk_a, 0);
	rb(stk_b, 0);
}

void	rrr(t_lst **stk_a, t_lst **stk_b)
{
	rra(stk_a, 0);
	rrb(stk_b, 0);
}

void	pa(t_lst **stk_a, t_lst **stk_b)
{
	t_lst	*temp;
	t_lst	*new;

	if (ft_size(*stk_b) < 1)
		return ;
	temp = *stk_b;
	new = *stk_b;
	temp = ft_newnode(new->content);
	ft_add_front(stk_a, temp);
	*stk_b = remove_first(*stk_b);
}

void	pb(t_lst **stk_a, t_lst **stk_b)
{
	t_lst	*temp;
	t_lst	*new;

	if (ft_size(*stk_a) < 1)
		return ;
	temp = *stk_a;
	new = *stk_a;
	temp = ft_newnode(new->content);
	ft_add_front(stk_b, temp);
	*stk_a = remove_first(*stk_a);
}
