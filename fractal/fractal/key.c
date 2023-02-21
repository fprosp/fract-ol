/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:19 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 16:14:52 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keypress(int key, t_data *strc)
{
	if (key == ESC)
		exit(0);
	return (0);
}

int	ft_close(int key, t_data *strc)
{
	(void)key;
	(void)strc;
	exit(0);
}

int	zoom_in(t_data *strc)
{
	strc->zoom *= 1.1;
	clear(strc);
	if (strc->mandelbrot == 1)
	{
		strc->mm_inter += 0.3;
		mandelbrot(strc);
	}
	else if (strc->julia == 1)
		julia(strc);
	return (0);
}

int	zoom_out(t_data *strc)
{
	strc->zoom /= 1.1;
	clear(strc);
	if (strc->mandelbrot == 1)
		mandelbrot(strc);
	else if (strc->julia == 1)
		julia(strc);
	return (0);
}

int	mousehook(int key, int x, int y, t_data *strc)
{
	(void)x;
	(void)y;
	if (key == ON_MOUSEDOWN)
		zoom_out(strc);
	else if (key == ON_MOUSEUP)
		zoom_in(strc);
	return (0);
}
