/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:33:29 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/12 18:19:46 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int plot_exe(t_data *strc, char **argv)
{
	if (strc->sierpinski == 1)
		sierpinski(strc);
	else if (strc->mandelbrot == 1)
		mandelbrot(strc);
	else if (strc->julia == 1)
		julia(strc);
	return (0);
}
