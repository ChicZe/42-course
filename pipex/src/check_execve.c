/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:58:18 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/27 13:47:46 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_child(char *path, t_args *pipex, char **commands, int pid)
{
	int	saved_out;

	saved_out = dup(1);
	if (pid == 0)
	{
		close(pipex->fds[0]);
		dup2(pipex->fds[1], STDOUT_FILENO);
		if (execve(path, commands, pipex->envp) == -1)
			return (-1);
		dup2(saved_out, STDOUT_FILENO);
		close(saved_out);
	}
	else
	{
		close(pipex->fds[1]);
		dup2(pipex->fds[0], STDIN_FILENO);
		waitpid(pid, 0, 0);
	}
	return (1);
}

int	last_command(t_args *pipex, char **commands, int j)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->file.out, STDOUT_FILENO);
		if (execve(pipex->cmd_path[j], commands, pipex->envp) == -1)
			return (-1);
	}
	return (1);
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
		if (ft_child(pipex->cmd_path[j], pipex, commands, pid) == -1)
			free_things(pipex, commands);
		j++;
		free_matrix(commands);
	}
	commands = ft_split(pipex->argv[i], 32);
	if (last_command(pipex, commands, j) == -1)
	{
		perror("[-]");
		free_things(pipex, commands);
	}
	free_things(pipex, commands);
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
