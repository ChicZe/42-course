#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct	s_data
{

	void	*mlx;
	void	*win;
	t_image	sprites[8];
}			t_data;

#endif