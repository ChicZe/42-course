/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:19:32 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/27 13:47:27 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>

typedef struct s_files
{
	int	inf;
	int	out;
}				t_files;

typedef struct s_args
{
	char	**argv;
	char	**envp;
	char	**cmd_path;
	int		argc;
	int		fds[2];
	t_files	file;
}				t_args;

/* parsing */
int		check_command(char **argv, char **path, t_args *pipex);

/* managing files */
int		manage_files(char **argv, int argc, t_args *pipex);

/* executing commands */
int		execute_command(t_args *pipex);

/* utils */
void	free_things(t_args *pipex, char **matrix);

#endif