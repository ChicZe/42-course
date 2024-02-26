/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:20:09 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/26 19:21:07 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char **argv, char **envp)
{
	char	**path;
	int		i;

	argv[0] = 0;
	i = -1;
	if (argc < 5)
		return (0);
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
	path = ft_split(envp[i], ':');
	if (!path)
		return (0);
	path[0] = ft_strtrim(path[0], "PATH=");
	//check_path(argv, path, envp);
	ft_printf("path = %s\n", path[5]);
	char *str = ft_strjoin(path[5], "/ls");
	if (access(str, X_OK) == 0)
	{
		ft_printf("funge!!!");
		return (1);
	}
	ft_printf("non funge\n");
	return (0);
}
