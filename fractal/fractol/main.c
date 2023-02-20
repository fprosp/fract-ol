/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:41:55 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/20 19:53:30 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
	mlx_loop(strc.mlx);
	return (EXIT_SUCCESS);
}
