/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:36:15 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/01 15:15:19 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	find_path(char **path, char *cmd)
{
	int		i;
	char	*str;

	i = -1;
	while (path[++i])
	{
		str = ft_strjoin(path[i], cmd);
		if (access(str, X_OK) == 0)
		{
			free(str);
			break ;
		}
		free(str);
	}
	if (!path[i])
	{
		free(cmd);
		free_matrix(path);
		perror("[-]");
		return (-1);
	}
	return (i);
}

int	check_command(char **argv, char **path, t_args *pipex)
{
	char	*cmd;
	int		i;
	int		j;
	char	*dup;

	i = 1;
	while (++i < 4)
	{
		if (!ft_strrchr(argv[i], '/'))
		{
			dup = ft_strjoin("/", argv[i]);
			if (find_path(path, argv[i]) < 0)
			{
				perror("[-]");
				free(dup);
				return (0);
			}
			free(dup);
		}
		else
			cmd = ft_strdup(argv[i]);
		if (access(cmd, X_OK) < 0)
		{
			free(cmd);
			return (0);
		}
		pipex->cmd = cmd;
	}
	return (1);
}
