/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:58:18 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/18 17:48:55 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_child(char *path, char **commands, char **envp, int i)
{
	int	fds[2];

	pipe(fds);
	if (i == 2)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		if (execve(path, commands, envp) == -1)
			ft_printf("error exec\n");
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], 0);
	}
	return (1);
}

int	execute_command(char **argv, char **envp, t_args *pipex)
{
	char	**commands;
	int		i;
	int		pid;
	int		j;

	j = 0;
	i = 1;
	while (++i < 4)
	{
		commands = ft_split(argv[i], 32);
		pid = fork();
		if (!pid)
			ft_child(pipex->cmd_path[j], commands, envp);
		else
			
		j++;
		free_matrix(commands);
	}
	dup2(pipex->file.out, 1);
	free_matrix(pipex->cmd_path);
	return (1);
}

int	manage_files(char **argv, int argc, t_args *pipex)
{
	pipex->file.inf = open(argv[0], O_RDONLY);
	if (pipex->file.inf < 0)
	{
		ft_printf("fd 0\n");
		perror("[-]");
		return (-1);
	}
	pipex->file.out = open(argv[argc - 1], O_CREAT | O_TRUNC, 777);
	if (pipex->file.out < 0)
	{
		close(pipex->file.inf);
		ft_printf("fd 1\n");
		perror("[-]");
		return (-1);
	}
	dup2(pipex->file.inf, 0);
	return (1);
}
