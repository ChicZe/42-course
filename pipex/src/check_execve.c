/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:39:10 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/01 20:09:12 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	execute_command(char **argv, char **envp, t_args *pipex)
{
	char	**commands;
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (++i < 4)
	{
		ft_printf("ciao\n");
		commands = ft_calloc(sizeof(char *), 2);
		ft_printf("argv = %s\n", argv[i]);
		ft_printf("cmd = %s- i = %d\n", pipex->cmd_path[j], i);
		commands = ft_split(argv[i], 32);
		execve(pipex->cmd_path[j], commands, envp);  // execve: (path whit the actual command ------ only the command ---- envp)
		free_matrix(commands);
		j++;
		ft_printf("last\n");
	}
	return (1);
}