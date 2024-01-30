/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:13:49 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/29 18:15:11 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_smallest(int *arr, int n)
{
	int	i;
	int	min;

	min = arr[0];
	i = -1;
	while (++i < n)
	{
		if (min < arr[i])
			min = arr[i];
	}
	return (i);
}