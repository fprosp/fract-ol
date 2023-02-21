/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:56:30 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 16:16:09 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc(t_data *d)
{
	d->ore = d->newre;
	d->oim = d->newim;
	d->newre = d->ore * d->ore - d->oim * d->oim + d->pr;
	d->newim = d->inc * d->ore * d->oim + d->pi;
}

void	calc1(t_data *d)
{
	d->pr = 1.5 * (d->x - LARG / 2) / (0.7 * d->zoom * LARG) - 0.735;
	d->pi = (d->y - ALT / 2) / (0.5 * d->zoom * ALT) + 0.36;
	d->newre = 0;
	d->newim = 0;
	d->ore = 0;
	d->oim = 0;
	d->i = 0;
}

int	mandelbrot(t_data *d)
{
	d->y = 0;
	while (d->y < ALT)
	{
		d->x = 0;
		while (d->x < LARG)
		{
			calc1(d);
			while (d->i < (d->mm_inter))
			{
				calc(d);
				if ((d->newre * d->newre + d->newim * d->newim) > 4)
				{
					my_mlx_pixel_put(d, d->x, d->y, color(d->i, d));
					break ;
				}
				d->i++;
			}
			d->x++;
		}
		d->y++;
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	return (0);
}
