/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:40 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/02 18:18:05 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

void	create_img(t_data *mlx)
{
	char	*relative_path = "calci.xpm";
	int		width;
	int		height;

	width = 1080;
	height = 720;
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, relative_path, &width, &height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	draw_square(t_data *img, int height, int width, int color)
{
	static int		i;
	static int		j;
	static int		count;
	int				prev;

	if (!count)
	{
		count = 0;
		i = 0;
		j = 0;
		count ++;
	}
	else
	{
		j += 50;
		i += 50;
	}
	height = i + 50;
	width = j + 50;
	count ++;
	while (i < height)
	{
		while (j < width)
		{
			mlx_pixel_put(img->mlx, img->win, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

int	onKeydown(int key, t_data *img)
{
	printf("%d\n", key);
	if (key == 65307)
		exit(0);
	else if (key == 119)
		draw_square(img, 1080, 720, 0x800080);
	else if (key == 115)
		draw_square(img, 1080, 720, 0x0000ff);
	else if (key == 97)
		draw_square(img, 1080, 720, 0x002b2f);
	else if (key == 100)
		draw_square(img, 1080, 720, 0x006d77);
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
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1080, 720, "test");
	create_img(&img);
	mlx_key_hook(img.win, onKeydown, &img);
	mlx_loop(img.mlx);
}
