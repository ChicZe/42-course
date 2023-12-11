/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:57:29 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/09 18:57:37 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.c"
#include "get_next_line/get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void	display_map(t_data *mlx, char **matrix)
{
	int	cols;
	int	rows;

	cols = 0;
	rows = 0;
	//map parsing
	while (matrix[cols])
	{
		while (matrix[cols][rows] != 0)
			rows++;
		cols++;
	}
	mlx->win = mlx_new_window(mlx->mlx, 64 * rows, 64 * cols, "test");
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
	while (get_next_line(fd) != NULL)
		i++;
	matrix = calloc(i + 1, sizeof(char *));
	//exit function
	close(fd);
	fd = open("Maps/secondMap.ber", O_RDONLY);
	while (--i >= 0)
	{
		line = get_next_line(fd);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = 0;
		matrix[i] = line;
	}
	close(fd);
	display_map(mlx, matrix);
}
