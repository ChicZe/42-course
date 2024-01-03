/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/03 18:23:54 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "handle_map.c"
#include "sprites_handle.c"
#include "controls.c"
#include "events.c"
#include "bonus/enemies.c"
#include "map_parsing.c"
#include "utils2.c"

void	file_validation(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("invalid file\n");
		exit (0);
	}
}

int	on_keydown(int key, t_data *img)
{
	img->player_cor.index = 4;
	if (key == 65307)
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

int	main(int argc, char **argv)
{
	t_data	img;
	char	*map_file;
	int		fd;

	if (argc != 2)
	{
		printf("invalid map argument\n");
		return (0);
	}
	file_validation(argv[1]);
	img.mlx = mlx_init();
	populate_map(&img, argv[1]);
	//show_text(&img);
	mlx_key_hook(img.win, on_keydown, &img);
	mlx_loop(img.mlx);
}
