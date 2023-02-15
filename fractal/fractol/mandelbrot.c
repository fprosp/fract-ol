/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:56:30 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/15 12:19:47 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#define Radius 10	/* convergence domain radius */
#define Cx 1.80	/* real coordinate of image center */
#define Cy 0	/*  imaginary coordinate of image center  */
#define Side 0.07	/* half side of the complex square domain */
#define M 700	/* number of pixels of each side of the image */
#define Num 255	/* max iteration number */

/* altenrative values: Cx 1.8616, 1.8622; Side 0.0015, 0.000030; Num 400, 700 */

int main()
{
	int p;
	int q;
	int n;
	int w;			/* background color */
	double x;
	double y;
	double xx;
	double yy;
	double Incx;
	double Incy;

	/* scanning of the complex domain */
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
			/* escape method */
			while (n <= Num)
			{
				++n;
				xx = x*x - y*y - Incx;
				yy = 2*x*y - Incy;
				x = xx;
				y = yy;
				if (x*x + y*y > Radius)	/* divergence condition */
				{
					w = n;
					n = Num;
				}

			}
			q++;
			fprintf(fp, "%c", w );	/* wrtie the escape speeds into the data file */
		}
		p++;
	}
	return (0);
}
