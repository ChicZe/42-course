/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:17:40 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/20 17:20:06 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_collectable(t_data *mlx)
{
	int			i;
	int			j;

	i = -1;
	while (mlx->matrix[++i] && mlx->player_cor.collected == 0)
	{
		j = -1;
		while (mlx->matrix[i][++j])
			if (mlx->matrix[i][j] == 'C')
				mlx->player_cor.collectable++;
	}
	printf("collectable = %d\n", mlx->player_cor.collectable);
	mlx->player_cor.collected += 1;
	printf("collected = %d\n", mlx->player_cor.collected);
	if (mlx->player_cor.collected == mlx->player_cor.collectable)
		open_exit(mlx);
}

int	check_collide(t_data *mlx, int x, int y)
{

	if (mlx->matrix[x][y] == '1')
		return (0);
	else if (mlx->matrix[x][y] == 'E')
	{
		if (open_exit(mlx) == 1)
			exit(0);
		return (0);
	}
	else if (mlx->matrix[x][y] == 'C')
	{
		handle_collectable(mlx);
		mlx->matrix[x][y] = 'P';
	}
	else if (mlx->matrix[x][y] == 'W')
		handle_enemies(mlx);
	mlx->matrix[mlx->player_cor.x][mlx->player_cor.y] = '0';
	return (1);
}

void	find_player(t_data *mlx)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (mlx->matrix[++i])
	{
		while (mlx->matrix[i][++j] != 0)
		{
			if (mlx->matrix[i][j] == 'P')
			{
				mlx->player_cor.x = i;
				mlx->player_cor.y = j;
			}
		}
		j = -1;
	}
}

void	player_movment(t_data *mlx, int horizontal, int vertical)
{
	int	x;
	int	y;

	find_player(mlx);
	x = mlx->player_cor.x;
	y = mlx->player_cor.y;
	printf("x = %d -- y = %d\n", x, y);
	if (horizontal == 1 && check_collide(mlx, x, y + 1) == 1)
		mlx->matrix[x][y + 1] = 'P';
	else if (horizontal == -1 && check_collide(mlx, x, y - 1) == 1)
		mlx->matrix[x][y - 1] = 'P';
	else if (vertical == -1 && check_collide(mlx, x + 1, y) == 1)
		mlx->matrix[x + 1][y] = 'P';
	else if (vertical == 1 && check_collide(mlx, x - 1, y) == 1)
		mlx->matrix[x - 1][y] = 'P';
	display_map(mlx);
}
