/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:03:02 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/13 21:30:53 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"
# include <math.h>
# define ALT 500
# define LARG 500 
# define MAX_ITERATIONS 80

typedef struct	s_data 
{
	void	*mlx_pt;
	void	*win_pt;
	void	*img;

	int		red;

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

int		plot_def(struct s_data *strc, char **argv);
int		wind_init(struct s_data  *st, char **argv);
int		plot_exe(struct s_data *strc, char **argv);

void	win_closer(struct s_data *st);



#endif
