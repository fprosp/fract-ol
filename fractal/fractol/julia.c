/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:00:08 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 16:13:29 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	call(t_data *d)
{
	d->newre = 1.5 * (d->x - LARG / 2) / (0.5 * d->zoom * LARG);
	d->newim = (d->y - ALT / 2) / (0.5 * d->zoom * ALT);
	d->i = 0;
}

void	call1(t_data *d)
{
	d->ore = d->newre;
	d->oim = d->newim;
	d->newre = d->ore * d->ore - d->oim * d->oim + d->jprm_1;
	d->newim = 2 * d->ore * d->oim + d->jprm_2;
}

int	julia(t_data *d)
{
	d->y = 0;
	while (d->y < ALT)
	{
		d->x = 0;
		while (d->x < LARG)
		{
			call(d);
			while (d->i < MAX_ITERATIONS)
			{
				call1(d);
				if ((d->newre * d->newre + d->newim * d->newim) > 5)
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
