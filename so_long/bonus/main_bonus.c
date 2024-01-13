/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/12 18:28:38 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	file_validation(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("invalid file\n");
		close(fd);
		exit(0);
	}
	close(fd);
}

int	on_keydown(int key, t_data *img)
{
	img->player_cor.index = 4;
	ft_printf("key = %d\n", key);
	if (key == 65307)
		exit_function(img);
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
	t_data	mlx;

	if (argc != 2)
	{
		ft_printf("invalid map argument\n");
		return (0);
	}
	ft_bzero(&mlx, sizeof(mlx));
	file_validation(argv[1]);
	mlx.mlx = mlx_init();
	if (!mlx.lives)
		mlx.lives = 2;
	initialize_imgs(&mlx);
	populate_map(&mlx, argv[1]);
	if (!mlx.move)
		display_moves(&mlx, 0);
	mlx_key_hook(mlx.win, on_keydown, &mlx);
	mlx_loop(mlx.mlx);
}
