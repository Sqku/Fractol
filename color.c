/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:33:46 by ahua              #+#    #+#             */
/*   Updated: 2015/03/23 16:15:19 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rainbow_color(double position, t_env *e)
{
	double			m;
	int				n;
	double			f;
	unsigned char	t;
	unsigned char	nmax;

	nmax = 6;
	m = nmax * position;
	n = (int)m;
	f = m - n;
	t = (int)(f * 255);
	if (position > 1.0)
	{
		if (position - (int)position == 0.0)
			position = 1.0;
		else
			position = position - (int)position;
	}
	set_color(e, t, n);
}

t_color	ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int		ft_color_to_int(t_color color)
{
	int c;

	c = color.r;
	c = c << 8;
	c += color.g;
	c = c << 8;
	c += color.b;
	return (c);
}

void	set_color(t_env *e, unsigned char t, int n)
{
	t_color c;

	if (n == 0)
		c = ft_rgb_to_color(255, t, 0);
	else if (n == 1)
		c = ft_rgb_to_color(255 - t, 255, 0);
	else if (n == 2)
		c = ft_rgb_to_color(0, 255, t);
	else if (n == 3)
		c = ft_rgb_to_color(0, 255 - t, 255);
	else if (n == 4)
		c = ft_rgb_to_color(t, 0, 255);
	else if (n == 5)
		c = ft_rgb_to_color(255, 0, 255 - t);
	else
		c = ft_rgb_to_color(0, 0, 0);
	e->img.color = ft_color_to_int(c);
}
