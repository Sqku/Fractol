/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 19:13:24 by ahua              #+#    #+#             */
/*   Updated: 2015/03/22 19:13:29 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_img(t_env *e, int x, int y)
{
	if (x > 0 && x < SIZE_X && y > 0 && y < SIZE_Y)
		ft_memcpy(&e->img.data[(x * 4) + (y * e->img.sizeline)],\
				&e->img.color, (size_t)(sizeof(int)));
}

void	redraw(t_env *e)
{
	if (e->fractol == 1)
		mandelbrot(e);
	else if (e->fractol == 2)
		julia(e);
	else if (e->fractol == 3)
		douady(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
}

int		loop_hook(t_env *e)
{
	if (e->re)
	{
		redraw(e);
		e->re = 0;
	}
	return (0);
}
