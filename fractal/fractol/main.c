/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:41:55 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 15:30:14 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int plot_exe(t_data *strc)
{
	if (win_init(strc) == EXIT_FAILURE)
	{
		free(strc->plot_str);
		return (EXIT_FAILURE);
	}
	if (strc->mandelbrot == 1)
		mandelbrot(strc);
	else if (strc->julia == 1)
		julia(strc);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	strc;
	
	strc.argc = argc;
	strc.argv = argv;
	if (argc < 2)
	{
		ft_printf(" Wrong use of program. Add the fractal set you want to represent: \
[mandelbroot] or [julia + 'param 1' 'param 2']\n");
		return (EXIT_FAILURE);
	}
	if (plot_def(&strc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	plot_exe(&strc);
	mlx_hook(strc.mlx_win, 2, 1L << 0, keypress, &strc);
	mlx_hook(strc.mlx_win, 17, (1L << 16), ft_close, &strc);
	mlx_mouse_hook(strc.mlx_win, mousehok, &strc);
	mlx_loop(strc.mlx);
	return (EXIT_SUCCESS);
}
