/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_gest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:51:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/01/16 02:17:26 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nc_gen(unsigned long ptr)
{
	int	i_arr;

	i_arr = 0;
	while (ptr > 0)
	{
		i_arr++;
		ptr = ptr / 16;
	}
	return (i_arr);
}

int	op(char *a_c, unsigned long ptr, char a, int base)
{
	int	i;
	int	rest_int;

	i = 0;
	while (ptr > 0)
	{
		rest_int = ptr % base;
		if (rest_int >= 10)
			a_c[i] = a + rest_int - 10;
		else
			a_c[i] = '0' + rest_int;
		i++;
		ptr = ptr / base;
	}
	return (i);
}

int	ft_get_conv(unsigned long ptr, char a, int base)
{
	char	*a_c;
	int		count;
	int		i;

	count = 0;
	if (ptr == 0)
		return (ft_putchar('0'));
	a_c = (char *)malloc(sizeof(char) * nc_gen(ptr));
	i = op(a_c, ptr, a, base) - 1;
	while (i >= 0)
	{
		count += ft_putchar(*(a_c + i));
		i--;
	}
	free(a_c);
	return (count);
}
