/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:57:29 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/20 17:28:05 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.c"
#include "get_next_line/get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void	reverse_matrix(t_data *mlx)
{
	int		i;
	int		count;
	char	*temp;

	printf("matrix = %s\n", mlx->matrix[0]);
	temp = calloc(sizeof(char *), strlen(mlx->matrix[i]) + 1);
	if (!temp)
		return ;
	count = 0;
	i = 0;
	while (mlx->matrix[count])
		count++;
	count--;
	while (i < count)
	{
		temp = mlx->matrix[i];
		mlx->matrix[i] = mlx->matrix[count];
		mlx->matrix[count] = temp;
		i++;
		count--;
	}
}

void	display_map(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->matrix[i])
	{
		while (mlx->matrix[i][j] != 0)
		{
			if (mlx->matrix[i][j] == '1')
				put_image(mlx, i, j, 1);
			else if (mlx->matrix[i][j] == '0')
				put_image(mlx, i, j, 2);
			else if (mlx->matrix[i][j] == 'P')
				put_image(mlx, i, j, 0);
			else if (mlx->matrix[i][j] == 'C')
				put_image(mlx, i, j, 5);
			else if (mlx->matrix[i][j] == 'E')
				put_image(mlx, i, j, 3);
			display_enemies(mlx, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	show_window(t_data *mlx)
{
	int	cols;
	int	rows;

	cols = 0;
	rows = 0;
	map_parsing(mlx);
	while (mlx->matrix[cols])
	{
		while (mlx->matrix[cols][rows] != 0)
			rows++;
		cols++;
	}
	mlx->win = mlx_new_window(mlx->mlx, 64 * rows, 64 * cols, "test");
	initialize_imgs(mlx);
	display_map(mlx);
}

void	populate_map(t_data *mlx)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("Maps/secondMap.ber", O_RDONLY);
	if (fd == -1)
		exit(0);
	while (get_next_line(fd) != NULL)
		i++;
	mlx->matrix = (char **)calloc(sizeof(char *), i + 1);
	//exit function
	close(fd);
	fd = open("Maps/secondMap.ber", O_RDONLY);
	while (--i >= 0)
	{
		line = get_next_line(fd);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = 0;
		mlx->matrix[i] = line;
	}
	close(fd);
	reverse_matrix(mlx);
	show_window(mlx);
}
