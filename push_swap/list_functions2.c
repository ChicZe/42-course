/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:40:25 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/13 16:57:34 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size(t_lst *lst)
{
	int	n;

	if (lst == NULL)
		return (0);
	n = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

int	*list_to_array(t_lst *list)
{
	int	len;
	int	*arr;
	int	i;

	len = ft_size(list);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		arr[i] = list->content;
		list = list->next;
	}
	return (arr);
}

void	free_list(t_lst **list)
{
	t_lst	*current;
	t_lst	*next_node;

	current = *list;
	while (current != NULL)
	{
		next_node = current->next; 
		free(current);
		current = next_node;
	}
	current = NULL;
}