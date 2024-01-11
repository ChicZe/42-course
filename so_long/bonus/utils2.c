/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:39:58 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/11 18:16:24 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_len(int n)
{
	int	count;

	count = 0;
	if (!n || n == 0)
		return (0);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	free_matrix(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
	mat = NULL;
}

int	exit_function(t_data *mlx)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	while (++j < 11)
		mlx_destroy_image(mlx->mlx, mlx->sprites[j].img);
	while (mlx->matrix[++i])
		free(mlx->matrix[i]);
	free(mlx->matrix);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	//free(mlx->win);
	exit(0);
}

char	*remove_char(char *str, int c)
{
	char	*dup;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	dup = ft_calloc(sizeof(char *), ft_strlen(str));
	if (!dup)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != c)
		{
			dup[j] = str[i];
			j++;
		}
	}
	free(str);
	return (dup);
}
