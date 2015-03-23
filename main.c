/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 19:14:10 by ahua              #+#    #+#             */
/*   Updated: 2015/03/22 19:14:19 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		e->zoom *= 1.1;
		e->move_x = (e->move_x + ((SIZE_X - (SIZE_X / 1.1)) / 2)
			+ (x - SIZE_X / 2) * (1 - (1 / 1.1))) * 1.1;
		e->move_y = (e->move_y + ((SIZE_Y - (SIZE_Y / 1.1)) / 2)
			+ (y - SIZE_Y / 2) * (1 - (1 / 1.1))) * 1.1;
		e->re = 1;
	}
	if (button == 5)
	{
		e->zoom /= 1.1;
		e->move_x = e->move_x / 1.1 - ((SIZE_X - (SIZE_X / 1.1)) / 2)
		/ 1.1 - (x - SIZE_X / 2) * 1.1 + (x - SIZE_X / 2);
		e->move_y = e->move_y / 1.1 - ((SIZE_Y - (SIZE_Y / 1.1)) / 2)
		/ 1.1 - (y - SIZE_Y / 2) * 1.1 + (y - SIZE_Y / 2);
		e->re = 1;
	}
	return (0);
}

int mousemove(int x, int y, t_env *env)
{
	if (env->fix == 0)
	{
		env->rc = (double)(x - SIZE_X / 2) / (double)env->zoom;
		env->ic = (double)(y - SIZE_Y / 2) / (double)env->zoom;
		env->re = 1;
	}
	return (0);
}

int	expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	e;

	init_fractol(ac, av, &e);
	init(&e);
	e.win = mlx_new_window(e.mlx, SIZE_X, SIZE_Y, "Fractol");
	e.img.img = mlx_new_image(e.mlx, SIZE_X, SIZE_Y);
	e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp, &e.img.sizeline,
		&e.img.endian);
	mlx_hook(e.win, 6, (1L << 6), mousemove, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
