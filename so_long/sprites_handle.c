/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:56:42 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/19 18:59:41 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *mlx, int x, int y, int i)
{
	int	h;
	int	w;

	h = x * 64;
	w = y * 64;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->sprites[i].img, w, h);
}

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
	mlx->sprites[3].img = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/fireplace.xpm", &width, &height);
	mlx->sprites[4].img = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/water.xpm", &width, &height);
	mlx->sprites[5].img = mlx_xpm_file_to_image(mlx->mlx,
			"sprites/wood.xpm", &width, &height);
}
