#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <math.h>

# define SIZE_X 810
# define SIZE_Y 720

typedef struct	s_img
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	void	*img;
	int 	color;
}				t_img;

typedef unsigned char	t_byte;

typedef struct	s_color
{
	t_byte		r;
	t_byte		g;
	t_byte		b;
}				t_color;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	int 	iter;
	long double	zoom;
	int		fix;
	long double	move_x;
	long double	move_y;
	t_img	img;
	int		re;
	long double	rc;
	long double	ic;
}				t_env;

void	ft_pixel_img(t_env *e, int x, int y);
void	mandelbrot(t_env *e);
int		key_hook(int keycode, t_env *e);
int		expose_hook(t_env *e);
int		loop_hook(t_env *e);
void	init(t_env *e);
void	init_v(t_env *e);
void	restart(int keycode, t_env *e);
void	redraw(t_env *e);
void	move_x(int keycode, t_env *e);
void	move_y(int keycode, t_env *e);
int		mousemove(int x, int y, t_env *);
void	julia(t_env *e);
void 	rainbow_color(double position, t_env *e);
t_color	ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b);
int		ft_color_to_int(t_color color);
void	move_iter(int keycode, t_env *e);


#endif