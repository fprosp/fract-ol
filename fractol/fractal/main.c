/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:41:55 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/12 18:31:04 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_data	strc;
	
	if (argc < 2)
	{
		ft_printf(" Wrong use of program. Add the fractal set you want to represent: \
				[sierpinski] or [mandelbroot] or [julia + 'prm_1' 'prm_2']\n");
		return (EXIT_FAILURE);
	}
	if (plot_def(&strc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (win_init(&strc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (plot_exe(&strc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
