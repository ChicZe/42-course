/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:45:54 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/20 19:57:36 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	matrix_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

void	print_list(t_lst *list)
{
	t_lst	*temp;
	int		i;

	i = 0;
	temp = list;
	while (temp)
	{
		ft_printf("data = %d\n", temp->content);
		temp = temp->next;
		i++;
	}
	ft_printf("stack n = %d\n", i);
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
	free_matrix(mat);
	return (new_mat);
}
