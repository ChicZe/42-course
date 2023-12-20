/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:06:44 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/20 17:10:09 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_exit(t_data *mlx)
{
	if (mlx->player_cor.collected == mlx->player_cor.collectable
		&& mlx->player_cor.collectable != 0)
	{
		/*   change the sprites to be "open"   */
		return (1);
	}
	return (0);
}

void	show_text(t_data *mlx)
{
	//char *str = "ciao";
	//mlx_set_font(mlx->mlx, mlx->win, "arial");
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, 120, "ciao");
}
