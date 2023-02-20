/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_gest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:19:26 by fprosper          #+#    #+#             */
/*   Updated: 2022/10/19 16:26:26 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{	
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(va_list arg)
{
	char	buffer;

	buffer = va_arg(arg, int);
	ft_putchar(buffer);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (i < (int)ft_strlen(s))
	{
		ft_putchar(*(s + i));
		i++;
	}
	return (i);
}

int	ft_put_id(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			return (write(1, "-2147483648", 11));
		}
		n *= (-1);
		return ((write(1, "-", 1)) + ft_get_conv(n, '0', 10));
	}
	else
		return (ft_get_conv(n, '0', 10));
}
