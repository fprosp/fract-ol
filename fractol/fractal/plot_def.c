-/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_def.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:20 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/08 15:33:59 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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

int	jpar_check(t_data *strc, char **argv)
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
            if (ft_isdigit((int)argv[j]) == 0
                && argv[i][j] != ' ' && argv[i][j] != '-' 
				&& argv[i][j] != '+' && argv[i][j] != '.')
                return (EXIT_FAILURE);
            if ((argv[i][j]== '-' || argv[i][j] == '+' )
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
	strc->sierpinski = 0;
	strc->mandelbrot = 0;
	strc->julia = 0;
	if (ft_strncmp("sierpinski", argv[1], 10) == 0)
		strc->sierpinski = 1;
	else if (ft_strncmp("mandelbrot", argv[1], 10) == 0)
		strc->mandelbrot = 1;
	else if (ft_strncmp("julia", argv[1], 5) == 0 && jpar_check(strc, argv) == 0)
	{
		strc->jprm_1 = atof(argv[2]);
    	strc->jprm_2 = atof(argv[3]);
		strc->julia = 1;
	}
	else
	{
		ft_printf("You have inserted invalid fractal set name, \
				or invalid julia parameter, try again with correct input\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
