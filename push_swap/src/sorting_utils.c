/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:13:49 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/20 19:59:34 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	find_min(int *arr, int n)
{
	int	min;
	int	i;

	i = -1;
	if (n == 0)
		return (-1);
	min = arr[0];
	while (++i < n)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return (min);
}

int	find_bigger(int n, int *arr, int target)
{
	int	i;
	int	*bigger;
	int	j;
	int	min;

	bigger = malloc(sizeof(int) * count_bigger(target, arr, n) + 1);
	j = 0;
	i = -1;
	while (++i < n)
	{
		if (arr[i] > target)
		{
			bigger[j] = arr[i];
			j++;
		}
	}
	i = -1;
	min = bigger[0];
	while (++i < j)
		if (bigger[i] < min)
			min = bigger[i];
	if (j == 0)
		min = find_min(arr, n);
	free(bigger);
	return (min);
}

int	find_smallest(int *arr, int n)
{
	int	i;
	int	min;
	int	j;

	j = 0;
	min = arr[0];
	i = -1;
	while (++i < n)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			j = i;
		}
	}
	return (j);
}
