/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:19:32 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/26 18:36:37 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
#define PIPEX_H

# include "libft/libft.h"


typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**path;
}				t_args;

int	check_path(char **argv, char **path, char **envp);

#endif