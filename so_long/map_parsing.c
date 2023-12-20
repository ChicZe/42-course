/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:23:05 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/20 18:06:20 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*   flood fill algorithm  */

void	check_elements(t_data *mlx)
{
	char	*elements;
	int		i;
	int		j;

	elements = "C10WEP";
	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
			if (!ft_strchr(elements, mlx->matrix[i][j]))
			{
				printf("insert valid elements");
				exit(0);
			}
			else if (mlx->matrix[i][j] == 'P')
				elements = "C10WE";
			else if (mlx->matrix[i][j] == 'E')
				elements = "C10WP";
	}
}

void	map_parsing(t_data *mlx)
{
	int	i;
	int	j;
	int	line;
	int	count;

	line = 0;
	count = 0;
	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[0][++j])
			line++;
		j = -1;
		while (mlx->matrix[i][++j])
			count++;
		if (line != count)
		{
			printf("the map is not regualar");
			exit(0);
		}
	}
	check_elements(mlx);
}
