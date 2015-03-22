/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 19:13:46 by ahua              #+#    #+#             */
/*   Updated: 2015/03/22 19:13:53 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_frac
{
	double rc;
	double ic;
	double rz;
	double iz;
	int x;
	int y;
	int a;
	double	r;
}				t_frac;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	int 	iter;
	double	zoom;
	int		fix;
	double	move_x;
	double	move_y;
	t_img	img;
	int		re;
	double	rc;
	double	ic;
	int 		fractol;
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
void	init_fractol(int ac, char **av, t_env *e);
void	douady(t_env *e);


#endif
