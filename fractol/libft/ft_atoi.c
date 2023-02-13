/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:28:24 by fprosper          #+#    #+#             */
/*   Updated: 2022/04/08 17:00:14 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	controllo_spazi(const char *str, int i)
{
	while (*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v' \
		|| *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	segno;

	i = 0;
	segno = 1;
	result = 0;
	i = controllo_spazi(str, i);
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
		{
			segno = -1;
		}
		i++;
	}
	while (*(str + i) <= '9' && *(str + i) >= '0')
	{
		result = result * 10 + (*(str + i) - '0');
		i++;
	}
	return (result * segno);
}
