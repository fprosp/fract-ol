/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_def.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:20 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/20 20:12:24 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	title_gen(t_data *strc)
{
	strc->plot_str = malloc(sizeof(char) * 34);
	if (!strc->plot_str)
		return (EXIT_FAILURE);
	if (strc->mandelbrot == 1)
		strc->plot_str = "Frattale di Mandelbrot";
	else if (strc->julia == 1)
		strc->plot_str = "Frattale di Julia ";
	return (EXIT_SUCCESS);
}

double	atof(const char *str)
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

int	par_check(char **argv)
{
    int i;
	int	j;

    i = 2;
	j = 0;
    while (i <= 3)
    {
		if (!argv[i])
			return (EXIT_FAILURE);
        while (argv[i][j] != '\0')
        {
            if (ft_isdigit(argv[i][j]) == 0 \
                	&& argv[i][j] != ' ' && argv[i][j] != '-' \
					&& argv[i][j] != '+' && argv[i][j] != '.')
                return (EXIT_FAILURE);
            if ((argv[i][j]== '-' || argv[i][j] == '+' ) \
            		&& (ft_isdigit((int)argv[i][j + 1]) == 0 || argv[i][j] == '\0'))
                return (EXIT_FAILURE);
            j++;
        }
        i++;
    }
	return (EXIT_SUCCESS);
}

int plot_def(t_data *strc, char **argv)
{
	strc->mandelbrot = 0;
	strc->julia = 0;
	if (ft_strncmp("mandelbrot", argv[1], 10) == 0)
		strc->mandelbrot = 1;
	else if (ft_strncmp("julia", argv[1], 5) == 0 \
			&& par_check(argv) == EXIT_SUCCESS)
	{
		strc->jprm_1 = atof(argv[2]);
    	strc->jprm_2 = atof(argv[3]);
		strc->julia = 1;
	}
	else
	{
		ft_printf("You have inserted invalid fractal set name,\
				or invalid julia parameter, try again with correct input\n");
		return (EXIT_FAILURE);
	}
	if (title_gen(strc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

