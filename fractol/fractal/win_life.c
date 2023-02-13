/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_life.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:06:58 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/12 18:54:26 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	close_win(t_data *strc)
{
	mlx_destroy_window(strc->mlx_pt, strc->win_pt);
	exit(EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_data *strc)
{
	char	*dst;

	strc->red = 0x00FF0000;
	dst = strc->addr + (strc->y * strc->line_length + strc->x * (strc->bits_per_pixel / 8));
	*(unsigned int*)dst = strc->red;
}

int	title_gen(t_data *strc, char **argv)
{
	char *tmp;

	strc->plot_str = malloc(sizeof(char) * 34);
	if (!strc->plot_str)
		return (EXIT_FAILURE);
	if (strc->sierpinski == 1)
		strc->plot_str = "Frattale di Sierpinski";
	else if (strc->mandelbrot == 1)
		strc->plot_str = "Frattale di Mandelbrot";
	else if (strc->julia == 1)
	{
		strc->plot_str = "Frattale di Julia con parametri: ";
		tmp = strc->plot_str;
		strc->plot_str = ft_strjoin(strc->plot_str, argv[2]);
		if (!strc->plot_str)
		{
			free(tmp);
			return (EXIT_FAILURE);
		}
		free(tmp);
		tmp = strc->plot_str;
		strc->plot_str = ft_strjoin(strc->plot_str, argv[3]);
		if (!strc->plot_str)
		{
			free(tmp);
			return (EXIT_FAILURE);
		}
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

int win_init(t_data  *strc, char **argv)
{
	if (title_gen(strc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
    strc->mlx_pt = mlx_init();
	if (strc->mlx_pt == NULL)
	{
		free(strc->plot_str);
		return (EXIT_FAILURE);
	}
	strc->win_pt = mlx_new_window(strc->mlx_pt, ALT, LARG, strc->plot_str);
	free(strc->plot_str);
	strc->img = mlx_new_image(strc->mlx_pt, ALT, LARG);
	strc->addr = mlx_get_data_addr(strc->img, &strc->bits_per_pixel, &strc->line_length, &strc->endian);
	if (strc->win_pt == NULL)
	{
		free(strc->win_pt);
		return (EXIT_FAILURE);
	}


	mlx_put_image_to_window(strc->mlx_pt, strc->win_pt, strc->img, 0, 0);
	mlx_loop(strc->mlx_pt);
	return (EXIT_SUCCESS);
}