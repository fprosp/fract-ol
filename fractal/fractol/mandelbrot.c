/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:56:30 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 15:51:53 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

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




















/*

#include "fract-ol.h"
#define Radius 10	// convergence domain radius 
#define Cx 1.80	// real coordinate of image center 
#define Cy 0	//  imaginary coordinate of image center  
#define Side 0.07	// half side of the complex square domain 
#define M 700	// number of pixels of each side of the image 
#define Num 255	// max iteration number 


// altenrative values: Cx 1.8616, 1.8622; Side 0.0015, 0.000030; Num 400, 700 

int main()
{
	int p;
	int q;
	int n;
	int w;			// background color
	double x;
	double y;
	double xx;
	double yy;
	double Incx;
	double Incy;

	// scanning of the complex domain 
	p = 1;
	while (p <= M)
	{
		Incy = Cy - Side + 2*Side/M*p;
		q = 1;
		while (q <= M)
		{
			Incx = Cx - Side + 2*Side/M*q;
			x = 0;
			y = 0;
			w = 200;
			// escape method 
			while (n <= Num)
			{
				++n;
				xx = x*x - y*y - Incx;
				yy = 2*x*y - Incy;
				x = xx;
				y = yy;
				if (x*x + y*y > Radius)	// divergence condition
				{
					w = n;
					n = Num;
				}

			}
			q++;
			fprintf(fp, "%c", w );	// wrtie the escape speeds into the data file 
		}
		p++;
	}
	return (0);
}

*/