/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:40 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/08 18:46:28 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "handle_map.c"
#include "player_movment.c"

void	create_img(t_data *mlx)
{
	char	*relative_path;
	int		width;
	int		height;

	relative_path = "calci.xpm";
	width = 1080;
	height = 720;
	mlx->sprites[0].img = mlx_xpm_file_to_image(mlx->mlx, relative_path,
			&width, &height);
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

int	on_keydown(int key, t_data *img)
{if (key == 65307)
		exit(0);
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

int	main(void)
{
	t_data	img;
	int		fd;

	img.mlx = mlx_init();
	populate_map(&img);
	create_img(&img);
	mlx_key_hook(img.win, on_keydown, &img);
	mlx_loop(img.mlx);
}
