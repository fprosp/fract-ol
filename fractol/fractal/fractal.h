/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:03:02 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/08 15:52:13 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>

# define ALT 500
# define LARG 500 
# define MAX_ITERATIONS 80
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "mlx_lib/mlx_lib1/mlx.h"
# include "mlx_lib/mlx_lib2/mlx.h"

typedef struct	s_data 
{
	void	*mlx_pt;
	void	*win_pt;

	int		red;
	int		argc;
	char	**argv;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int 	y;
	int		fractal;
	double	jprm_1;
	double	jprm_2;
	char	*plot_str;
	int		sierpinski;
	int		mandelbrot;
	int		julia;
	
}				t_data;

int		wind_init(struct s_data  *st);
void	win_closer(struct s_data *st);



#endif
