/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:57:29 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/13 19:29:08 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_map(t_data *mlx, int index)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j] != 0)
		{
			if (mlx->matrix[i][j] == '1')
				put_image(mlx, i, j, put_wall_image(i));
			else if (mlx->matrix[i][j] == '0')
				put_image(mlx, i, j, 2);
			else if (mlx->matrix[i][j] == 'P')
				put_image(mlx, i, j, index);
			else if (mlx->matrix[i][j] == 'C')
				put_image(mlx, i, j, 5);
			else if (mlx->matrix[i][j] == 'E')
				put_image(mlx, i, j, 3);
			display_enemies(mlx, i, j);
		}
	}
	handle_lives(mlx, i, j);
}

void	show_window(t_data *mlx)
{
	int	cols;
	int	rows;

	cols = 0;
	rows = 0;
	while (mlx->matrix[cols])
	{
		while (mlx->matrix[cols][rows] != 0)
			rows++;
		cols++;
	}
	map_parsing(mlx);
	mlx->win = mlx_new_window(mlx->mlx, 64 * rows, 64 * (cols + 0.5),
			"so_long");
	display_map(mlx, 8);
}

void	fill_matrix(t_data *mlx, char *line, int fd)
{
	int	i;

	i = -1;
	while (++i <= mlx->matrix_i)
	{
		line = get_next_line(fd);
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		mlx->matrix[i] = line;
	}
}

void	populate_map(t_data *mlx, char *map_file)
{
	char	*line;
	int		fd;
	int		len;

	len = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_function(mlx);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		len ++;
	}
	mlx->matrix_i = len;
	mlx->matrix = ft_calloc(sizeof(char *), mlx->matrix_i + 1);
	if (!mlx->matrix)
		return ;
	close(fd);
	fd = open(map_file, O_RDONLY);
	fill_matrix(mlx, line, fd);
	close(fd);
	show_window(mlx);
}
