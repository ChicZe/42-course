/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:59:18 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/23 19:23:22 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	check_rev(t_lst **sa, t_lst **sb)
{
	int		i;
	int		count;
	t_lst	*temp;

	temp = *sa;
	count = 1;
	i = -1;
	while (temp->next && ++i < ft_size(*sa))
	{
		if (temp->content > temp->next->content)
			count++;
	}
	i = 0;
	if (count == ft_size(*sa))
		while (++i < ft_size(*sa))
			pb(sa, sb);
}

void	check_sorted(char **input, int argc)
{
	int		i;
	int		count;
	t_lst	*sa;

	sa = create_stack(input);
	count = 1;
	i = -1;
	while (input[++i])
	{
		if (i == argc -1)
			break ;
		if (ft_atoi(input[i]) < ft_atoi(input[i + 1]))
			count++;
	}
	if (count == argc)
	{
		free_matrix(input);
		exit(0);
	}
	rev_one_sort(&sa, input);
	free_list(&sa);
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
				write(2, "Error\n", 6);
				free_matrix(input);
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
	char	*line;

	i = -1;
	while (++i < argc)
	{
		n = ft_atoi(input[i]);
		str = ft_itoa(n);
		if (input[i][0] == '+' && input[i][1] != ' ' && input[i][1])
		{
			free(str);
			line = ft_itoa(n);
			str = ft_strjoin("+", line);
			free(line);
		}
		if (ft_strncmp(str, input[i], ft_strlen(input[i])) != 0)
		{
			write(2, "Error\n", 6);
			exit_function(input, str);
		}
		free(str);
	}
	check_duplicates(input, argc);
}
