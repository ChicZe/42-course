/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:52:55 by nromito           #+#    #+#             */
/*   Updated: 2024/04/30 12:24:37 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	tokenizer(char *input)
{
	printf("%s\n", input);
	printf("tokenizer\n");
}

char *lexer(char *input)
{
	char **token_input;
	char tokens[10];
	int	i;

	i = -1;
	token_input = ft_split(input, 32);
	while (token_input[++i])
	{
		if ((access(token_input[i], X_OK)))
			tokens[i] = 'C';
		else
			tokens[i] = 'S';
	}
	for (int i = 0; tokens[i]; i++)
		printf("%c ", tokens[i]);
	return (0);
}
