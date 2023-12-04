/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:40 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/04 16:16:06 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	get_map_size(t_data *mlx)
{
	int		i;
	int		rows;
	int		cols;
	char	*buffer;
	int		fd;
	int		bytes_read;

	buffer = calloc(20000, sizeof(char));
	i = -1;
	fd = open("Maps/mainMap.ber", O_RDONLY);
	if (fd == -1)
	{
		printf("map not found");
		exit(0);
	}
	bytes_read = read(fd, buffer, 20000);
	if (bytes_read == -1)
	{
		printf("error reading file");
		exit(0);
	}
	buffer[bytes_read] = 0;
	while (buffer[++i] != '\n')
		cols++;
	i = -1;
	while (buffer[++i] != 0)
		if (buffer[i] == '\n')
			rows ++;
	rows++;
	mlx->win = mlx_new_window(mlx->mlx, 64 * 5, 64 * 5, "test");
}

void	create_img(t_data *mlx)
{
	char	*relative_path = "calci.xpm";
	int		width;
	int		height;

	width = 1080;
	height = 720;
	mlx->sprites[0].img = mlx_xpm_file_to_image(mlx->mlx, relative_path, &width, &height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites[0].img, 0, 0);
}

void	player_movment(t_data *mlx, int horizontal, int vertical)
{
	static int	x;
	static int	y;

	if (horizontal == 1)
		x += 64;
	else if (horizontal == -1)
		x -= 64;
	else if (vertical == -1)
		y += 64;
	else if (vertical == 1)
		y -= 64;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites[0].img, x, y);
}

int	onKeydown(int key, t_data *img)
{
	printf("%d\n", key);
	if (key == 65307)
		exit(0);
	else if (key == 119)
		player_movment(img, 0, 1);
	else if (key == 115)
		player_movment(img, 0, -1);
	else if (key == 97)
		player_movment(img, -1, 0);
	else if (key == 100)
		player_movment(img, 1, 0);
	return (0);
}

int	onMouseMove(int pos)
{
	printf("%d\n", pos);
	return (0);
}

int	get_mouse(void *img)
{
	int		x;
	int		y;
	t_data	*data;

	data = (t_data *)img;
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	printf("x: %d\ny: %d", x, y);
	return (0);
}

int	main(void)
{
	t_data	img;
	int		fd;

	img.mlx = mlx_init();
	get_map_size(&img);
	create_img(&img);
	mlx_key_hook(img.win, onKeydown, &img);
	mlx_loop(img.mlx);
}
