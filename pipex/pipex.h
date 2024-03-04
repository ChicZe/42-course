/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:19:32 by ciusca            #+#    #+#             */
/*   Updated: 2024/03/04 20:44:48 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define stdint 0
# include "libft/libft.h"
# include <sys/wait.h>

typedef struct s_files
{
	int	fds[2];
}				t_files;

typedef struct s_args
{
	char	**argv;
	char	**envp;
	char	**cmd_path;
	t_files	file;
}				t_args;

/* parsing */
int	check_command(char **argv, char **path, t_args *pipex);

/* managing files */
int	manage_files(char **argv, int argc, t_args *pipex);

/* executing commands */
int	execute_command(char **argv, char **envp, t_args *pipex);

#endif