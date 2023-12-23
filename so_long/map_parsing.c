/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:23:05 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/21 20:55:58 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_data *mlx)
{
	char	**temp;
	int		i;
	int		j;

	i = -1;
	temp = mlx->matrix;
	//printf("temp = %s\n", temp[0]);
	printf("x = %d -- y = %d\n", mlx->player_cor.x, mlx->player_cor.y);
	flood_fill(temp, mlx->player_cor.x, mlx->player_cor.y);
	/*while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (temp[i][j] == 'E')
			{
				printf("no valid path");
				exit(0);
			}
		}
	}*/
	//while (temp[++i])
	//	printf("%s\n", temp[i]);
}

void	check_walls(t_data *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
		{
			if ((i == 0 || i == 15) && mlx->matrix[i][j] != '1')
			{
				printf("invalid walls");
				exit(0);
			}
			else if (mlx->matrix[i][0] != '1'
					|| mlx->matrix[i][strlen(mlx->matrix[i]) - 1] != '1')
			{
				printf("invalid walls");
				exit(0);
			}
		}
	}
}

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
		{
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
	check_walls(mlx);
	check_path(mlx);
}
