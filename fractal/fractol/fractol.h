/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:03:02 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 16:15:58 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"
# include <math.h>
# define ALT 600
# define LARG 600 
# define MAX_ITERATIONS 30

typedef struct s_data
{
	int			argc;
	char		**argv;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	char		*plot_str;
	int			red;
	int			x;
	int			y;
	double		jprm_1;
	double		jprm_2;

	int			mandelbrot;
	double		ore;
	double		oim;
	double		newre;
	double		pi;
	double		pr;
	double		inc;
	double		newim;
	double		zoom;
	int			i;
	int			mm_inter;	
	int			julia;
	double		cim;
	double		cre;
}				t_data;

typedef enum e_keys
{
	ESC = 53,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
}	t_keys;

int		plot_def(t_data *strc, char **argv);
int		wind_init(t_data *strc, char **argv);
int		win_init(t_data *strc);
void	win_closer(t_data *strc);
int		sierpinski(t_data *strc);
int		mandelbrot(t_data *strc);
int		julia(t_data *strc);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		color(int inter, t_data *data);
int		keypress(int key, t_data *strc);
int		ft_close(int key, t_data *strc);
int		mousehook(int key, int x, int y, t_data *strc);
int		clear(t_data *strc);

#endif
