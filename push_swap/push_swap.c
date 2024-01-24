/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:37:06 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/23 16:21:02 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_lst *sa, t_lst *sb)
{
	t_lst	*temp1;
	t_lst	*temp2;

	temp1 = sa;
	temp2 = sb;
	ft_printf("stack_a ---- stack_b\n");
	while (temp1)
	{
		if (temp2)
		{
			ft_printf("sa =   %d ---- sb =    %d\n", temp1->content, temp2->content);
			temp1 = temp1->next;
			temp2 = temp1->next;
		}
		else
		{
			ft_printf("stack_a =   %d\n", temp1->content);
			temp1 = temp1->next;
		}
	}
}

void	print_list(t_lst *list)
{
	t_lst	*temp;

	temp = list;
	while (temp)
	{
		ft_printf("data = %d\n", temp->content);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	char	**input;
	t_lst	*stack_a;
	//t_lst	*stack_b;

	//stack_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		input = ft_split(argv[1], 32);
		input = matrix_join(argv[0], input);
	}
	else
		input = argv;
	//input parsing;
	//lis_algo;
	stack_a = create_stack(input);
	get_arr(&stack_a);
	//print_list(stack_a);
}
