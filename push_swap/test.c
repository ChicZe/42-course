/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:45:54 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/20 18:17:59 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		matrix_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

char	**ft_matrix_dup(char **matrix)
{
	int		i;
	int		size;
	char	**dup;

	size = 0;
	while (matrix[size])
		size++;
	dup = ft_calloc(sizeof(char *), size + 1);
	i = -1;
	while (matrix[++i])
		dup[i] = ft_strdup(matrix[i]);
	return (dup);
}

void	free_matrix(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
}

char	**matrix_join(char *string, char **mat)
{
	//char	*temp;
	char	**new_mat;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 1;
	while (mat[i])
		i++;
	new_mat = ft_calloc(sizeof(char *), i + 2);
	if (!new_mat)
		return (NULL);
	new_mat[0] = ft_strdup(string);
	while (j <= i)
	{
		new_mat[j] = ft_strdup(mat[k]);
		j++;
		k++;
	}
	return (new_mat);
}