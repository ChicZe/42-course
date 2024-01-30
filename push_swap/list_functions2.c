/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:40:25 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/29 15:52:29 by ciusca           ###   ########.fr       */
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
