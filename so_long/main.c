/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:40 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/18 15:29:57 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "handle_map.c"
#include "sprites_handle.c"
#include "controls.c"

int	on_keydown(int key, t_data *img)
{
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

int	main(void)
{
	t_data	img;
	int		fd;

	img.mlx = mlx_init();
	populate_map(&img);
	mlx_key_hook(img.win, on_keydown, &img);
	mlx_loop(img.mlx);
}
