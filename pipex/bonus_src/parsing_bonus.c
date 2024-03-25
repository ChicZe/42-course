/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:36:15 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/25 18:19:54 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	find_path(char **path, char *cmd, t_args *pipex)
{
	int				i;
	char			*str;
	static int		j;
	char			**mat;

	i = -1;
	while (path[++i])
	{
		str = ft_strjoin(path[i], cmd);
		mat = ft_split(str, 32);
		if (!mat)
			return (-1);
		if (access(mat[0], X_OK) == 0)
		{
			pipex->cmd_path[j] = ft_strdup(mat[0]);
			j++;
			free(str);
			free_matrix(mat);
			return (i);
		}
		free_matrix(mat);
		free(str);
	}
	return (-1);
}

int	check_command(char **argv, char **path, t_args *pipex)
{
	char	*cmd;
	int		i;

	pipex->argv = ft_calloc(sizeof(char *), pipex->argc);
	cmd = ft_strdup(path[0]);
	free(path[0]);
	path[0] = ft_strtrim(cmd, "PATH=");
	free(cmd);
	i = 1;
	while (++i < 4)
	{
		if (!ft_strrchr(argv[i], '/'))
			cmd = ft_strjoin("/", argv[i]);
		else
			cmd = argv[i];
		if (find_path(path, cmd, pipex) < 0)
		{
			free(cmd);
			return (0);
		}
		pipex->argv[i] = ft_strtrim(cmd, "/");
		free(cmd);
	}
	return (1);
}
