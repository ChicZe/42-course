/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:39:10 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/04 20:43:28 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	execute_command(char **argv, char **envp, t_args *pipex)
{
	char	**commands;
	int		i;
	int		j;
	int		pid;

	j = 0;
	i = 1;
	while (++i < 4)
	{
		pipe(pipex->file.fds);
		commands = ft_split(argv[i], 32);
		pid = fork();
		if (pid == 0)
			execve(pipex->cmd_path[j], commands, envp);  // * execve: (path whit the actual command ------ only the command ---- envp)
		else
			wait(&pid);
		free_matrix(commands);
		j++;
	}
	i = 1;
	while (++i < 4)
		free(argv[i]);
	free_matrix(pipex->cmd_path);
	return (1);
}

int	manage_files(char	**argv, int	argc, t_args *pipex)
{
	pipex->file.fds[0] = open(argv[0], O_RDWR);
	pipex->file.fds[1] = open(argv[argc - 1], O_CREAT | O_TRUNC, 777);
	if (pipex->file.fds[0] < 0 || pipex->file.fds[1] < 0)
	{
		ft_printf("fd error\n");
		perror("[-]");
		return (-1);
	}
	return (1);
}
