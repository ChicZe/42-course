/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:40:07 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/20 19:59:05 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*ft_last(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_add_front(t_lst **lst, t_lst *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

void	ft_add_back(t_lst **alst, t_lst *new)
{
	t_lst	*tmp;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = ft_last(*(alst));
			tmp->next = new;
		}
	}
}

t_lst	*ft_newnode(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_lst	*create_stack(char **input)
{
	t_lst	*stack_a;
	t_lst	*temp;
	int		i;

	stack_a = ft_newnode(ft_atoi(input[0]));
	temp = stack_a;
	i = 1;
	while (input[i])
	{
		temp->next = ft_newnode(ft_atoi(input[i]));
		temp = temp->next;
		i++;
	}
	return (stack_a);
}
