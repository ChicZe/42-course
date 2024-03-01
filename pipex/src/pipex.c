/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:20:09 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/01 19:50:42 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	int		i;
	t_args	pipex;

	i = -1;
	if (argc != 5)
		return (0);
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
	path = ft_split(envp[i], ':');
	if (!path)
		return (0);
	pipex.cmd_path = ft_calloc(sizeof(char *), 3);
	if (!pipex.cmd_path)
		return (1);
	if (check_command(argv, path, &pipex) == 0)
	{
		perror("[-]");
		free_matrix(path);
		return (1);
	}
	free_matrix(path);
	execute_command(argv, envp, &pipex);
	return (0);
}
