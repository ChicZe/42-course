/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:39:10 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/29 18:33:33 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	execute_command(char **argv, char **envp, t_args *pipex)
{
	char	**commands;

	argv[0] = 0;
	commands = ft_calloc(sizeof(char), 2);
	commands[0] = ft_strdup(pipex->cmd);
	ft_printf("path = %s\n", pipex->cmd);
	execve(pipex->cmd, commands, envp);
	return (1);
}