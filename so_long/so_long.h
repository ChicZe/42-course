/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:47:40 by ciusca            #+#    #+#             */
/*   Updated: 2023/12/21 20:49:27 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_player
{
	int			x;
	int			y;
	int			collected;
	int			collectable;
}			t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**matrix;
	t_image		sprites[9];
	t_player	player_cor;
}			t_data;

void	initialize_imgs(t_data *mlx);
void	player_movment(t_data *mlx, int horizontal, int vertical);
void	put_image(t_data *mlx, int x, int y, int i);
int		open_exit(t_data *mlx);
void	show_text(t_data *mlx);
void	display_enemies(t_data *mlx, int i, int j);
void	handle_enemies(t_data *mlx);
void	map_parsing(t_data *mlx);
char	*ft_strchr(const char *s, int c);
void	flood_fill(char **map, int i, int j);

#endif