/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:47:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/03 18:12:25 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <string.h>

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
	int			index;
}			t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**matrix;
	t_image		sprites[11];
	t_player	player_cor;
}			t_data;

int		put_wall_image(t_data *mlx, int i);
char	*remove_char(char *str, int c);
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
void	find_player(t_data *mlx);
char	**ft_matrix_dup(char **matrix);
size_t	ft_len(const char *src);

#endif