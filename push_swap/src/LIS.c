/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:06:26 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/05 19:31:21 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*fill_lis(int *arr, t_lis *utils, int *lis, int *prev)
{
	int	i;
	int	j;

	i = -1;
	while (++i < utils->n)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
				if (lis[i] > utils->max_length)
				{
					utils->max_length = lis[i];
					utils->end_index = i;
				}
			}
		}
	}
	return (prev);
}

int	*ft_lis(int arr[], int n, t_lis *utils)
{
	int	*prev;
	int	*lis;
	int	i;

	utils->max_length = -1;
	utils->end_index = 0;
	utils->n = n;
	lis = (int *)malloc(sizeof(int) * n);
	if (!lis)
		return (NULL);
	prev = (int *)malloc(sizeof(int) * (n + 1));
	if (!prev)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		lis[i] = 1;
		prev[i] = -1;
	}
	prev[i] = -1;
	prev = fill_lis(arr, utils, lis, prev);
	prev[utils->n] = utils->end_index;
	free(lis);
	return (prev);
}

int	*rev_arr(int *arr, int n)
{
	int	*new;
	int	i;
	int	j;

	i = 0;
	new = malloc(sizeof(int) * n);
	if (!new)
		return (NULL);
	j = n - 1;
	while (i < n)
	{
		new[i] = arr[j];
		i++;
		j--;
	}
	free(arr);
	return (new);
}

int	*final_lis(int *arr, int *index, int n, t_lis *lis_arr)
{
	int	i;
	int	last;
	int	*temp;
	int	len;

	len = 0;
	last = index[n - 1];
	while (last != -1)
	{
		last = index[last];
		len++;
	}
	temp = malloc(sizeof(int) * len);
	if (!temp)
		return (NULL);
	last = index[n - 1];
	i = -1;
	while (last != -1 && ++i < len)
	{
		temp[i] = arr[last];
		last = index[last];
	}
	temp = rev_arr(temp, len);
	lis_arr->n = len;
	return (temp);
}

int	*get_arr(t_lst **stk_a, t_lis *lis_arr)
{
	int		*sa;
	t_lst	*temp;
	int		i;
	int		*prev;
	int		*sorted_arr;

	i = 0;
	temp = *stk_a;
	sa = malloc(sizeof(int) * ft_size(*stk_a));
	while (temp)
	{
		sa[i] = temp->content;
		i++;
		temp = temp->next;
	}
	prev = ft_lis(sa, i, lis_arr);
	sorted_arr = final_lis(sa, prev, i + 1, lis_arr);
	free(prev);
	free(sa);
	return (sorted_arr);
}
