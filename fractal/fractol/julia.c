/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:00:08 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 14:39:36 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	call(t_data *d)
{
	d->newre = 1.5 * (d->x - LARG / 2) / (0.5 * d->zoom * LARG); // + d->movex;
	d->newim = (d->y - ALT / 2) / (0.5 * d->zoom * ALT); // + d->mvy;
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

































/* 
#include "fractal.h"
#define Radius 10
#define Cx 0.7454294
#define Cy 0.113089
#define Side 1.7
#define M 700
#define Num 1024

int main()
{
	int p, q, n, w;
	double x, y, xx, yy, Incx, Incy;
	
	FILE *fp;
	fp = fopen("Julia.raw","w");
	for (p = 1; p <= M; p++)
	{
		Incy = - Side + 2*Side/M*p;
		printf("%i %%\n", p*100/M);
		for (q = 1; q <= M; q++)
		{
			Incx = - Side + 2*Side/M*q;
			x =  Incx;
			y =  Incy;
			w = 200;
			for ( n = 1; n <= Num; ++n)
			{
				xx = x*x - y*y - Cx;
				yy = 2*x*y - Cy;
				x = xx;
				y = yy;
				if ( x*x + y*y > Radius )
				{
					w = n;
					n = Num;
				}
			}
			fprintf(fp, "%c", w/4 );
		}
	}
	fclose(fp);
    return (0);
}


*/