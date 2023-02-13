/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:05:56 by fprosper          #+#    #+#             */
/*   Updated: 2022/05/23 15:05:02 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_check(const char *s, va_list args)
{
	if (*(s) == 'c')
		return (ft_print_char(args));
	else if (*(s) == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*(s) == 'p')
		return (write(1, "0x", 2) + \
		ft_get_conv(va_arg(args, unsigned long), 'a', 16));
	else if (*(s) == 'd' || *(s) == 'i')
		return (ft_put_id(va_arg(args, int)));
	else if (*(s) == 'u')
		return (ft_get_conv(va_arg(args, unsigned int), '0', 10));
	else if (*(s) == 'x')
		return (ft_get_conv(va_arg(args, unsigned int), 'a', 16));
	else if (*(s) == 'X')
		return (ft_get_conv(va_arg(args, unsigned int), 'A', 16));
	else if (*(s) == '%')
		return (ft_putchar(*(s)));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, s);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == '%')
		{
			i++;
			count += type_check((s + i), args);
			i++;
		}
		if (!*(s + i))
			return (count);
		if (*(s + i) != '%')
		{	
			count++;
			ft_putchar(*(s + i));
			i++;
		}
	}
	return (count);
}
