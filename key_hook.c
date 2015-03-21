/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 21:29:20 by ahua              #+#    #+#             */
/*   Updated: 2015/03/03 22:19:53 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw(t_env *e)
{
	ft_bzero(e->img.data, SIZE_X * SIZE_Y * 4);
	julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
}

void	move_x(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		e->move_x -= 10;
		e->re = 1;
	}
	else if (keycode == 124)
	{
		e->move_x += 10;
		e->re = 1;
	}
}

void	move_y(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		e->move_y -= 10;
		e->re = 1;
	}
	else if (keycode == 125)
	{
		e->move_y += 10;
		e->re = 1;
	}
}

void	move_iter(int keycode, t_env *e)
{
	if ((keycode == 78) && (e->iter > 1))
	{
		e->iter -= 5;
		e->re = 1;
	}
	else if ((keycode == 69) && (e->iter < 1500))
	{
		e->iter += 5;
		e->re = 1;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 92)
	{
		if (e->fix == 0)
			e->fix = 1;
		else
			e->fix = 0;
	}
	move_x(keycode, e);
	move_y(keycode, e);
	move_iter(keycode, e);
	restart(keycode, e);
	return (0);
}