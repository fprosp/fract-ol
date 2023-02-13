/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:06:58 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/08 15:52:45 by fprosper         ###   ########.fr       */
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

int	title_gen(t_data *strc)
{
	strc->plot_str = malloc(sizeof(char) * 25);
	if (!strc->plot_str)
		return (1);
	if (strc->sierpinski == 1)
		strc->plot_str = "Frattale di Sierpinski";
	else if (strc->mandelbrot == 1)
		strc->plot_str = "Frattale di Mandelbrot";
	else if (strc->julia == 1)
		strc->plot_str = "Frattale di Julia";
	return (0);
}

int win_init(t_data  *strc)
{
	if (title_gen(strc) == 1)
		return (1);
    strc->mlx_pt = mlx_init();
	if (strc->mlx_pt == NULL)
	{
		free(strc->plot_str);
		return (1);
	}
	strc->win_pt = mlx_new_window(strc->mlx_pt, ALT, LARG, strc->plot_str);
	free(strc->plot_str);
	strc->img = mlx_new_image(strc->mlx_pt, ALT, LARG);
	strc->addr = mlx_get_data_addr(strc->img, &strc->bits_per_pixel, &strc->line_length, &strc->endian);
	if (strc->win_pt == NULL)	
	{
		free(strc->win_pt);
		return (1);
	}
	strc->x = 0;
	strc->y = 0;
	while (strc->y < 500)
	{
		strc->x = 0;  
		while (strc->x < 500)
		{
			my_mlx_pixel_put(strc->x);
			strc->x++;
		}
		strc->y++;
	}
	mlx_put_image_to_window(strc->mlx_pt, strc->win_pt, strc->img, 0, 0);
	mlx_loop(strc->mlx_pt);
	return (0);
}
