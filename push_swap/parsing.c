/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:59:18 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/10 19:12:40 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorted(char **input, int argc)
{
	int	i;
	int count;

	count = 1;
	i = 0;
	while (input[++i])
	{
		if (i == argc -1)
			break;
		if (ft_atoi(input[i]) < ft_atoi(input[i + 1]))
			count++;

	}
	if (count == argc - 1)
		exit(0);
}

void	check_duplicates(char **input, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]) && i != j)
			{
				ft_printf("Error\n");
				exit(0);
			}
		}
	}
	check_sorted(input, argc);
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
