/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:06:44 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/28 15:19:37 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_matrix_dup(char **matrix)
{
	int		i;
	int		size;
	char	**dup;

	size = -1;
	while (matrix[size])
		size++;
	dup = calloc(sizeof(char*), size + 1);
	i = -1;
	while (matrix[++i])
		dup[i] = strdup(matrix[i]);
	return (dup);
}

void	flood_fill(char **tab, int i, int j)
{
	if (i < 0 || j < 0 || i >= 5 || j >= 23)
		return ;
	if (tab[i][j] == 'F' || tab[i][j] == '1' || tab[i][j] == 'W' )
		return ;
	if (tab[i][j] == 'E')
	{
		tab[i][j] = 'F';
		return ;
	}
	tab[i][j] = 'F';
	flood_fill(tab, i -1, j);
	flood_fill(tab, i +1, j);
	flood_fill(tab, i, j - 1);
	flood_fill(tab, i, j + 1);
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

size_t	ft_len(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}