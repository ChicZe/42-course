/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:19:32 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/29 18:25:53 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

typedef struct s_args
{
	char	**argv;
	char	**envp;
	char	*cmd;
}				t_args;

/* parsing */
int	check_command(char **argv, char **path, t_args *pipex);

/* executing commands */
int	execute_command(char **argv, char **envp, t_args *pipex);

#endif