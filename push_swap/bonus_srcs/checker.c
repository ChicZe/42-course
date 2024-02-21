/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:33:10 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/21 11:48:17 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	main(int argc, char **argv)
{
	char	**input;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		input = ft_split(argv[1], 32);
		if (!input)
			return (1);
	}
	else
		input = ft_matrix_dup(&argv[1]);
	argc = matrix_len(input);
	check_invalid(input, argc);
	init_check(input);
}
