/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_matrix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:34:29 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/13 18:28:21 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**trim_matrix(t_data *mlx)
{
	int		i;
	int		index;
	int		j;
	char	**dup;

	index = 0;
	i = 0;
	j = mlx->matrix_i;
	ft_printf("height = %d\n", j);
	while (mlx->matrix[i][0] == '\n')
		i++;
	while (mlx->matrix[j][0] == '\n')
		j--;
	dup = ft_calloc(sizeof(char), (j - i) + 2);
	if (!dup)
		return (NULL);
	while (i <= j)
	{
		dup[index] = ft_strdup(mlx->matrix[i]);
		i++;
		index++;
	}
	mlx->matrix = ft_matrix_dup(dup);
	free_matrix(dup);
	return(mlx->matrix);
}
