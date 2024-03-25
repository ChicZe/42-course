/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:58:18 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/25 18:22:17 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_child(char *path, t_args *pipex, char **commands, int pid)
{
	if (pid == 0)
	{
		close(pipex->fds[0]);
		dup2(pipex->fds[1], STDOUT_FILENO);
		execve(path, commands, pipex->envp);
		return (1);
	}
	else
	{
		close(pipex->fds[1]);
		dup2(pipex->fds[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		return (1);
	}
	return (0);
}

int	execute_command(t_args *pipex)
{
	char	**commands;
	int		i;
	int		pid;
	int		j;

	j = 0;
	i = 1;

	while (++i < pipex->argc - 2)
	{
		pipe(pipex->fds);
		commands = ft_split(pipex->argv[i], 32);
		pid = fork();
		ft_child(pipex->cmd_path[j], pipex, commands, pid);
		j++;
		free_matrix(commands);
	}
	commands = ft_split(pipex->argv[i], 32);
	dup2(pipex->file.out, STDOUT_FILENO);
	execve(pipex->cmd_path[j], commands, pipex->envp);
	free_matrix(pipex->argv);
	free_matrix(pipex->cmd_path);
	return (1);
}

int	manage_files(char **argv, int argc, t_args *pipex)
{
	pipex->file.inf = open(argv[1], O_RDONLY, 0777);
	if (pipex->file.inf < 0)
	{
		ft_printf("fd 0\n");
		perror("[-]");
		return (-1);
	}
	pipex->file.out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->file.out < 0)
	{
		close(pipex->file.inf);
		ft_printf("fd 1\n");
		perror("[-]");
		return (-1);
	}
	pipex->argc = argc;
	dup2(pipex->file.inf, 0);
	return (1);
}
