/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:59:18 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/13 19:31:09 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_lst **sa)
{
	t_lst	*temp;
	int		count;

	temp = *sa;
	count = 1;
	while (temp->next != 0)
	{
		if (temp->content < temp->next->content)
			count++;
		temp = temp->next;
	}
	if (count == ft_size(*sa))
		return (1);
	return (0);
}

void	check_sorted(char **input, int argc)
{
	int	i;
	int count;

	count = 1;
	i = -1;
	while (input[++i])
	{
		if (i == argc -1)
			break;
		if (ft_atoi(input[i]) < ft_atoi(input[i + 1]))
			count++;
	}
	if (count == argc)
	{
		free_matrix(input);
		ft_printf("ciao %d\n", i);
		exit(1);
	}
}

void	check_duplicates(char **input, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]) && i != j)
			{
				ft_printf("Error\n");
				free_matrix(input);
				ft_printf("ciao %d\n", i);
				exit(1);
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

	i = -1;
	while (++i < argc)
	{
		n = ft_atoi(input[i]);
		str = ft_itoa(n);
		if (input[i][0] == '+')
			str = ft_strjoin("+", str);
		if (ft_strncmp(str, input[i], ft_strlen(input[i])) != 0)
		{
			ft_printf("Error\n");
			free(str);
			if (input != NULL)
				free_matrix(input);
			ft_printf("ciao %d\n", i);
			exit(1);
		}
		free(str);
	}
	check_duplicates(input, argc);
}
