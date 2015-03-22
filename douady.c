/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   douady.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 19:11:57 by ahua              #+#    #+#             */
/*   Updated: 2015/03/22 19:12:07 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	douady(t_env *e)
{
	t_frac	frac;

	frac.x = -1;
	while (frac.x++ < SIZE_X)
	{
		frac.y = -1;
		while (frac.y++ < SIZE_Y)
		{
			frac.rz = (double)(frac.x + e->move_x) / e->zoom - 1.4;
			frac.iz = (double)(frac.y + e->move_y) / e->zoom - 1.2;
			frac.rc = -0.123;
			frac.ic = 0.745;
			frac.a = 0;
			while ((frac.rz * frac.rz + frac.iz * frac.ic) < 4
				&& frac.a < e->iter)
			{
				frac.r = frac.rz;
				frac.rz = (frac.r * frac.r) - (frac.iz * frac.iz) + frac.rc;
				frac.iz = (2.0 * frac.r * frac.iz) + frac.ic;
				frac.a++;
			}
			rainbow_color((double)frac.a / (double)e->iter, e);
			ft_pixel_img(e, frac.x, frac.y);
		}
	}
}
