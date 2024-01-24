/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:06:26 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/24 21:02:14 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_array(int *arr, int last)
{
	int	count;
	int	i;

	i = last - 1;
	count = 1;
	while (i >= 0)
	{
		if (arr[i] < arr[last])
		{
			last = i;
			count++;
		}
		i--;
	}
	return (count);
}

/*int	*sort_lis(int *arr, int last)
{
	int	*sorted_arr;
	int	i;
	int	j;

	//len = count_array(arr, last);
	sorted_arr = malloc(sizeof(int) * 10);
	if (!sorted_arr)
		return (0);
	j = 0;
	i = last;
	while (arr[j] != arr[last])
	{
		
	}
	return (sorted_arr);
}*/

/*int	check_biggest(int *arr, int n)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < n)
	{
		if (arr[i] > max)
			max = i;
		i++;
	}
	return (max);
}*/

int	*printLIS(int arr[], int n) {
    int* lis = (int*)malloc(sizeof(int) * n + 1);
    int* prev = (int*)malloc(sizeof(int) * n);

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

    // Printing the LIS
	prev[n] = endIndex;
	return (prev);
    /*printf("Longest Increasing Subsequence: \n");
    while (i < n + 1) {
		//ft_printf("end index = %d\n", endIndex);
        printf("arr = %d\n", prev[i]);
		i++;
        //endIndex = prev[endIndex];
    }

    free(lis);
    free(prev);*/
}

int	*rev_arr(int *arr, int n)
{
	int	*new;
	int	i;
	int	j;

	new = malloc(sizeof(int) * n);
	if (!new)
		return (NULL);
	j = n -1;
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
	last = arr[n - 1];
	while (last != -1)
	{
		last = index[last];
		len++;
	}
	temp = malloc(sizeof(int) * len);
	if (!temp)
		return (NULL);
	last = index[last];
	i = 0;
	while (last != -1)
	{
		temp[i] = arr[last];
		last = index[last];
		i++;
	}
	rev_arr(temp, len);
	return (temp);
}

void	get_arr(t_lst **stk_a)
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
	sorted_arr = final_lis(sa, prev, i);
	for(int i = 0; i < 5; i++)
		ft_printf("sorted arr = %d\n", sorted_arr[i]);
	// get final array
}
