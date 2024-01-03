/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:17:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/03 17:41:51 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	change_sprites(t_data *mlx, int horizontal, int vertical)
{
	if (horizontal == 1)
		return (0);
	else if (horizontal == -1)
		return (6);
	else if (vertical == -1)
		return (8);
	else if (vertical == 1)
		return (7);
	return (0);
}

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
	mlx->player_cor.collected += 1;
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
	mlx->player_cor.index = change_sprites(mlx, horizontal, vertical);
	if (horizontal == 1 && check_collide(mlx, x, y + 1) == 1)
	{
		mlx->matrix[x][y + 1] = 'P';
		mlx->player_cor.index = 0;
	}
	else if (horizontal == -1 && check_collide(mlx, x, y - 1) == 1)
	{
		mlx->matrix[x][y - 1] = 'P';
		mlx->player_cor.index = 6;
	}
	else if (vertical == -1 && check_collide(mlx, x + 1, y) == 1)
	{
		mlx->matrix[x + 1][y] = 'P';
		mlx->player_cor.index = 8;
	}
	else if (vertical == 1 && check_collide(mlx, x - 1, y) == 1)
	{
		mlx->matrix[x - 1][y] = 'P';
		mlx->player_cor.index = 7;
	}
	display_map(mlx, mlx->player_cor.index);
}
