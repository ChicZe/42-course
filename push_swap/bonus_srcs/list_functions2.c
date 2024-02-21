/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:40:25 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/21 11:48:28 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
