/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:00:08 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/04 12:28:40 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
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
