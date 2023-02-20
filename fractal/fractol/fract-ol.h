/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:03:02 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/20 19:39:15 by fprosper         ###   ########.fr       */
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
	int		argc;
	char	**argv;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	char	*plot_str;
	int		red;
	int		x;
	int 	y;
	double	jprm_1;
	double	jprm_2;

	int		mandelbrot;
	int		julia;

}				t_data;

int		plot_def(struct s_data *strc, char **argv);
int		wind_init(struct s_data *strc, char **argv);
int		win_init(struct s_data *strc);
void	win_closer(struct s_data *strc);
int		sierpinski(struct s_data *strc);
int		mandelbrot(struct s_data *strc);
int		julia(struct s_data *strc);





#endif
