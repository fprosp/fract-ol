/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:41:55 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/08 15:34:37 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int plot_exe(t_data *strc)
{
	if (strc->sierpinski == 1)
		sierpinski(strc);
	else if (strc->mandelbrot == 1)
		mandelbrot(strc);
	else if (strc->julia == 1)
		julia(strc);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	strc;
	
	strc.argc = argc;
	strc.argv = argv;
	if (argc < 2)
	{
		ft_printf(" Wrong use of program. Add the fractal set you want to represent: \
				[sierpinski] or [mandelbroot] or [julia + 'prm_1' 'prm_2']\n");
		return (0);
	}
	if (plot_def(&strc) == 1)
		return (0);
	if (win_init(strc) == 1)
		return (0);
	if (plot_exe(&strc) == 1)
		return (1);
	return (0);
}
