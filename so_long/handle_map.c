/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:57:29 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/05 18:12:22 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.c"
#include "get_next_line/get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void	display_map(t_data *mlx, char **matrix, int count)
{
	int	cols;
	int	rows;

	cols = 0;
	rows = 0;
	/*while (cols < count)
	{
		while (matrix[cols][rows] != 0)
			rows++;
		printf("%s\n", matrix[cols]);
		cols++;
	}*/
	//printf("cols = %d \n rows = %d", cols, rows);
	mlx->win = mlx_new_window(mlx->mlx, 64 * 6, 64 * 6, "test");
}

void	populate_map(t_data *mlx)
{
	char	**matrix;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("Maps/secondMap.ber", O_RDONLY);
	if (fd == -1)
		exit(0);
	while (get_next_line(fd) != 0)
		i++;
	matrix = malloc(sizeof(char) * i + 1);
	matrix[i] = NULL;
	close(fd);
	fd = open("Maps/secondMap.ber", O_RDONLY);
	i--;
	while (i >= 0)
	{
		line = get_next_line(fd);
		line[strlen(line) - 1] = 0;
		matrix[i] = line;
		//printf("%s\n", matrix[i]);
		i--;
	}
	//printf("matrix 0 = %s \nmatrix last = %s", matrix[0], matrix[4]);
	close(fd);
	display_map(mlx, matrix, i);
}
