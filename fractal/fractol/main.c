/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:41:55 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/15 15:24:24 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int win_init(t_data  *strc)
{
    strc->mlx = mlx_init();
	if(!strc->mlx)
		return (EXIT_FAILURE);
	strc->mlx = mlx_new_window(strc->mlx, ALT, LARG, strc->plot_str);
	strc->img = mlx_new_image(strc->mlx, ALT, LARG);
	strc->addr = mlx_get_data_addr(strc->img, &strc->bits_per_pixel, &strc->line_length, &strc->endian);
	return (EXIT_SUCCESS);
}

/*

int plot_exe(t_data *strc)
{
	if (win_init(strc) == EXIT_FAILURE)
	{
		free(strc->plot_str);
		return (EXIT_FAILURE);
	}
	if (strc->sierpinski == 1)
		sierpinski(strc);
	else if (strc->mandelbrot == 1)
		mandelbrot(strc);
	else if (strc->julia == 1)
		julia(strc);
	return (EXIT_SUCCESS);
}

*/

int	main(int argc, char **argv)
{
	t_data	strc;
	
	strc.argc = argc;
	strc.argv = argv;
	if (argc < 2)
	{
		ft_printf(" Wrong use of program. Add the fractal set you want to represent: \
					[sierpinski] or [mandelbroot] or [julia + 'prm_1' 'prm_2']\n");
		return (EXIT_FAILURE);
	}
	if (plot_def(&strc, argv) == EXIT_FAILURE /* \
			|| plot_exe(&strc) == EXIT_FAILURE */ )
		return (EXIT_FAILURE);
	
	mlx_loop(strc.mlx);
	return (EXIT_SUCCESS);
}
