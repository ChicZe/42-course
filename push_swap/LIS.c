/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:06:26 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/26 15:49:32 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*printLIS(int arr[], int n)
{
    int* lis = (int*)malloc(sizeof(int) * n);
    int* prev = (int*)malloc(sizeof(int) * n + 1);
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        prev[i] = -1;
    }
    int maxLength = 1;
    int endIndex = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
                if (lis[i] > maxLength) {
                    maxLength = lis[i];
                    endIndex = i;
                }
            }
        }
    }
	prev[n] = endIndex;
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
	return (new);
}

int	*final_lis(int *arr, int *index, int n)
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
	i = 0;
	while (last != -1 && i < len)
	{
		temp[i] = arr[last];
		last = index[last];
		i++;
	}
	temp = rev_arr(temp, i);
	return (temp);
}

int	*get_arr(t_lst **stk_a)
{
	int		*sa;
	t_lst	*temp;
	int		i;
	int		*sorted_arr;
	int		*prev;

	i = 0;
	temp = *stk_a;
	sa = malloc(sizeof(int) * ft_size(*stk_a));
	while (temp)
	{
		sa[i] = temp->content;
		i++;
		temp = temp->next;
	}
	prev = printLIS(sa, i);
	sorted_arr = final_lis(sa, prev, i + 1);
	free(sa);
	free(prev);
	return (sorted_arr);
}
