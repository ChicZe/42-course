/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:12:29 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/20 17:21:33 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_enemies(t_data *mlx, int i, int j)
{
	if (mlx->matrix[i][j] == 'W')
		put_image(mlx, i, j, 4);
}

void	handle_enemies(t_data *mlx)
{
	printf("you touched water!");
	exit(0);
}