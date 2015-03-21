
#include "fractol.h"

void	ft_pixel_img(t_env *e, int x, int y)
{
	if (x > 0 && x < SIZE_X && y > 0 && y < SIZE_Y)
		ft_memcpy(&e->img.data[(x * 4) + (y * e->img.sizeline)],\
				&e->img.color, (size_t)(sizeof(int)));
}

void	mandelbrot(t_env *e)
{
	long double rc;
	long double ic;
	long double rz;
	long double	iz;
	int x;
	int y;
	int a;
	long double	r;

	x = 0;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			rc = (long double)(x + e->move_x) / e->zoom - 2.1;
			ic = (long double)(y + e->move_y) / e->zoom - 1.2;
			rz = 0;
			iz = 0;
			a = 0;
			while ((rz * rz + iz * ic) < 4.0 && a < e->iter)
			{
				r = rz;
				rz = (r * r) - (iz * iz) + rc;
				iz = (2.0 * r * iz) + ic;
				a++;
			}
			rainbow_color((double)a / (double)e->iter, e);
			ft_pixel_img(e, x, y);
			y++;
		}
		x++;
	}

}


void	julia(t_env *e)
{
	long double rc;
	long double ic;
	long double rz;
	long double	iz;
	int x;
	int y;
	int a;
	long double	r;

	x = 0;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			rz = (long double)(x + e->move_x) / e->zoom - 1.4;
			iz = (long double)(y + e->move_y) / e->zoom - 1.2;
			rc = e->rc;
			ic = e->ic;
			a = 0;
			while ((rz * rz + iz * ic) < 4 && a < e->iter)
			{
				r = rz;
				rz = (r * r) - (iz * iz) + rc;
				iz = (2.0 * r * iz) + ic;
				a++;
			}
			rainbow_color((double)a / (double)e->iter, e);
			ft_pixel_img(e, x, y);
			y++;
		}
		x++;
	}

}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		e->zoom *= 1.1;
		e->move_x = (e->move_x + ((SIZE_X - (SIZE_X / 1.1)) / 2) + (x - SIZE_X / 2) * (1 - (1 / 1.1))) * 1.1;
		e->move_y = (e->move_y + ((SIZE_Y - (SIZE_Y / 1.1)) / 2) + (y - SIZE_Y / 2) * (1 - (1 / 1.1))) * 1.1;
		e->re = 1;
	}
	if (button == 5)
	{
		e->zoom /= 1.1;
		e->move_x = e->move_x / 1.1 - ((SIZE_X - (SIZE_X / 1.1)) / 2) / 1.1 - (x - SIZE_X / 2) * 1.1 + (x - SIZE_X / 2);
		e->move_y = e->move_y / 1.1 - ((SIZE_Y - (SIZE_Y / 1.1)) / 2) / 1.1 - (y - SIZE_Y / 2) * 1.1 + (y - SIZE_Y / 2);
		e->re = 1;
	}
	return (0);
}

int		mousemove(int x, int y, t_env *env)
{
	if (env->fix == 0)
		{
			env->rc = (long double)(x - SIZE_X / 2) / (long double)env->zoom;
			env->ic = (long double)(y - SIZE_Y / 2) / (long double)env->zoom;
			env->re = 1;
		}
	return (0);
}

int	expose_hook(t_env *e)
{
	julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int	loop_hook(t_env *e)
{
	if (e->re)
	{
		redraw(e);
		e->re = 0;
	}
	return (0);
}

int	main()
{
	t_env	e;

	init(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, SIZE_X, SIZE_Y, "Fractol");
	e.img.img = mlx_new_image(e.mlx, SIZE_X, SIZE_Y);
	e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp, &e.img.sizeline, &e.img.endian);
	mlx_hook(e.win, 6, (1L<<6), mousemove, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}