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

void	init(t_env *e)
{
	e->zoom = 300;
	e->move_x = 0;
	e->move_y = 0;
	e->iter = 100;
	e->rc = 0;
	e->ic = 0;
	e->fix = 0;
	e->mlx = mlx_init();
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