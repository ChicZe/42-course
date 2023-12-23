/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:06:44 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/21 20:50:37 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int i, int j)
{
	if (i < 0 || j < 0 || j > 29 || i > 15)
		return ;
	if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E')
		map[i][j] = 'F';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}

int	open_exit(t_data *mlx)
{
	if (mlx->player_cor.collected == mlx->player_cor.collectable
		&& mlx->player_cor.collectable != 0)
	{
		/*   change the sprites to be "open"   */
		return (1);
	}
	return (0);
}

void	show_text(t_data *mlx)
{
	//char *str = "ciao";
	//mlx_set_font(mlx->mlx, mlx->win, "arial");
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, 120, "ciao");
}
