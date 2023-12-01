/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:40 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/01 20:06:19 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data img, int height, int width, int color)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			put_pixel(&img, i, j, color);
			j++;
			color ++;
		}
		j = 0;
		i++;
	}
}

int	onKeydown(int key, t_data img)
{
	printf("%d\n", key);
	if (key == 65307)
		exit(0);
	return (0);
}

int	onMouseMove(int pos)
{
	printf("%d\n", pos);
	return (0);
}
int	get_mouse(void *img)
{
	int	x;
	int	y;
	t_data *data;
	
	data = (t_data*)img;
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	printf("x: %d\ny: %d", x, y);
	return (0);
}

int	main(void)
{
	t_data	img;
	int		i;
	int		j;
	int		x = 0;
	int		y = 0;

	i = 0;
	j = 0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1080, 720, "test");
	img.img = mlx_new_image(img.mlx, 1080, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_square(img, 1080, 720, 1);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_key_hook(img.win, onKeydown, &img);
	//mlx_mouse_get_pos(img.mlx, img.win, &x, &y);
	//mlx_loop_hook(img.mlx, get_mouse, &img);

	mlx_loop(img.mlx);
}
