/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_def.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:20 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/23 17:14:58 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	int_part;
	double	dec_part;
	double	sign;
	int		i;

	int_part = 0.0;
	dec_part = 0.0;
	sign = 1.0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1.0;
	while (ft_isdigit(*str))
		int_part = int_part * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			dec_part += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (int_part + dec_part));
}

int	par_check(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (EXIT_FAILURE);
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 0 \
				&& argv[i] != ' ' && argv[i] != '-' \
				&& argv[i] != '+' && argv[i] != '.')
			return (EXIT_FAILURE);
		if ((argv[i] == '-' || argv[i] == '+' ) \
				&& (ft_isdigit((int)argv[i + 1]) == 0 || argv[i] == '\0'))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	var_init(t_data *strc)
{
	strc->mandelbrot = 0;
	strc->julia = 0;
	strc->zoom = 0.9;
	strc->x = 0;
	strc->y = 0;
	strc->inc = 2;
}

void	jvar_init(t_data *strc)
{
	strc->jprm_1 = ft_atof(strc->argv[2]);
	strc->jprm_2 = ft_atof(strc->argv[3]);
	strc->mm_inter = MAX_ITERATIONS;
}

int	plot_def(t_data *strc, char **argv)
{
	var_init(strc);
	if (ft_strncmp("mandelbrot", argv[1], 10) == 0 \
			&& par_check(argv[2]) == EXIT_SUCCESS)
	{
		strc->mm_inter = ft_atoi(argv[2]);
		if (strc->mm_inter < 0 || strc->mm_inter > 200)
			return (EXIT_FAILURE);
		strc->mandelbrot = 1;
	}
	else if (ft_strncmp("julia", argv[1], 5) == 0 \
			&& par_check(argv[2]) == EXIT_SUCCESS \
			&& par_check(argv[3]) == EXIT_SUCCESS)
	{
		strc->julia = 1;
		jvar_init(strc);
	}
	else
	{
		ft_printf("You have inserted invalid fractal set name, \
or invalid julia parameter, try again with correct input\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
