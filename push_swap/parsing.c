/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:59:18 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/09 19:50:39 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(char **input, int argc)
{
	int	*arr;
	int	i;
	int	*hash;

	arr = malloc(sizeof(int) * argc);
	if (!arr)
		return ;
	hash = malloc(sizeof(int) * argc);
	if (!hash)
		return ;
	i = -1;
	while (++i < argc)
		hash[i] = 0;
	i = -1;
	while (++i < argc)
	{
		arr[i] = ft_atoi(input[i]);
		if (hash[arr[i]] == 1)
		{
			ft_printf("Error\n");
			exit(0);
		}
		hash[arr[i]] = 1;
	}
}

void	check_invalid(char **input, int argc)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	while (++i < argc)
	{
		n = ft_atoi(input[i]);
		str = ft_calloc(sizeof(char *), ft_strlen(input[i]) + 1);
		if (!str)
			return ;
		str = ft_itoa(n);
		if (input[i][0] == '+')
			str = ft_strjoin("+", str);
		else if (input[i][0] == '-')
			str = ft_strjoin("-", str);
		if (ft_strncmp(str, input[i], ft_strlen(input[i])) != 0)
		{
			ft_printf("Error\n");
			free(str);
			exit(0);
		}
		free(str);
	}
	check_duplicates(input, argc);
}
