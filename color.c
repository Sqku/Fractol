#include "fractol.h"

void rainbow_color(double position, t_env *e)
{
	t_color c;

	if (position > 1.0)
	{
		if (position - (int)position == 0.0)position = 1.0;
		else position = position - (int)position;
	}
 
  unsigned char nmax = 6;
  double m = nmax * position;
 
  int n = (int)m;
 
  double f = m - n;
  unsigned char t = (int)(f * 255);

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