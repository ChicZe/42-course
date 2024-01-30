/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:59:18 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/28 18:21:21 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(char **input, int argc)
{
	int	arr[argc];
	int	i;
	int	hash_size;
	int	*hash;

	hash_size = 10000;
	hash = malloc(sizeof(int) * hash_size);
	if (!hash)
		return ;
	i = -1;
	while (++i < hash_size)
		hash[i] = 0;
	i = -1;
	while (++i < argc)
	{
		arr[i] = ft_atoi(input[i]);
		if (hash[arr[i]] == 1)
		{
			ft_printf("duplicates numbers\n");
			exit(0);
		}
		hash[arr[i]] = 1;
	}
}
