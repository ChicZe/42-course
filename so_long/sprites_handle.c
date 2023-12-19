/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:56:42 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/19 16:56:42 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_imgs(t_data *mlx)
{
	int		width;
	int		height;

	width = 1080;
	height = 720;
	mlx->sprites[0].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/calci1.xpm",
			&width, &height);
	mlx->sprites[1].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/wall1.xpm",
			&width, &height);
	mlx->sprites[2].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/ground.xpm",
			&width, &height);
	mlx->sprites[3].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/fireplace.xpm",
		&width, &height);
	mlx->sprites[4].img = mlx_xpm_file_to_image(mlx->mlx, "sprites/water.xpm",
		&width, &height);
}
