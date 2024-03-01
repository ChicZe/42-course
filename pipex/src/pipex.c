/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:20:09 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/29 18:29:30 by ciusca           ###   ########.fr       */
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
