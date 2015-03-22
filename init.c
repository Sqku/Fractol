/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 21:28:15 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 22:20:49 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(int ac, char **av, t_env *e)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			e->fractol = 1;
		else if (ft_strcmp(av[1], "julia") == 0)
			e->fractol = 2;
		else if (ft_strcmp(av[1], "douady") == 0)
			e->fractol = 3;
		else
		{
			ft_putendl_fd("fractol: Wrong Arguments", 2);
			ft_putendl_fd("fractol: use mandelbrot / julia / douady", 2);
			exit(0);
		}
	}
	else
	{
		ft_putendl_fd("usage: ./fractol <mandelbrot / julia / douady>", 2);
		exit (0);
	}
}

void	init(t_env *e)
{
	e->zoom = 300;
	e->move_x = 0;
	e->move_y = 0;
	e->iter = 50;
	e->rc = 0;
	e->ic = 0;
	e->fix = 1;
	e->re = 1;
	e->mlx = mlx_init();
	if (e->mlx == 0)
	{
		ft_putstr_fd("fdf: ca sent le fdp tout d'un coups\n", 2);
		exit (0);
	}
}

void	init_v(t_env *e)
{
	e->rc = 0;
	e->ic = 0;
	e->iter = 100;
	e->zoom = 300;
	e->move_x = 0;
	e->move_y = 0;
}

void	restart(int keycode, t_env *e)
{
	if (keycode == 49)
	{
		init_v(e);
		e->re = 1;
	}
}