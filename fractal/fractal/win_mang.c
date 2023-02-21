/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_mang.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:29:35 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 16:17:51 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	win_init(t_data *strc)
{
	strc->mlx = mlx_init();
	if (!strc->mlx)
		return (EXIT_FAILURE);
	strc->mlx_win = mlx_new_window(strc->mlx, ALT, LARG, "Frattali");
	strc->img = mlx_new_image(strc->mlx, ALT, LARG);
	strc->addr = mlx_get_data_addr(strc->img, &strc->bits_per_pixel, \
			&strc->line_length, &strc->endian);
	return (EXIT_SUCCESS);
}

int	clear(t_data *strc)
{
	mlx_destroy_image(strc->mlx, strc->img);
	strc->img = mlx_new_image(strc->mlx, ALT, LARG);
	strc->addr = mlx_get_data_addr(strc->img, &strc->bits_per_pixel, \
			&strc->line_length, &strc->endian);
	return (0);
}
