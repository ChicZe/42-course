/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:26:12 by nromito           #+#    #+#             */
/*   Updated: 2024/04/30 10:21:10 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*ft_readline(char *str)
{
	char *input;

	input = readline(str);
	if (!input)
		return (0);
	add_history(input);
	rl_on_new_line();
	return (input);
}


int	main(int argc, char **argv)
{
	char	*input;

	if (argv[1])
		argc = 2;
	argc++;
	while(1)
	{
		//todo: garbage collector
		input = ft_readline("<minishell> ");
		//se input e' null semplicemente ti riparte il while
		if (input)
		{
			lexer(input);

		}
	}
}