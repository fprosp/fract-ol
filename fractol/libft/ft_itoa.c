/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:53:30 by fprosper          #+#    #+#             */
/*   Updated: 2022/05/06 10:51:00 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	nn_gen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

size_t	num_extract(int n, size_t k)
{
	size_t	n1;
	size_t	h;
	size_t	n2;
	size_t	temp;

	n1 = (n / k);
	h = k * 10;
	n2 = ((n / h) * 10);
	temp = n1 - n2;
	return (temp);
}

void	num_alloc(char *sn, size_t nn, int n, size_t check)
{
	size_t	k;
	size_t	nn_bis;

	k = 1;
	nn_bis = nn;
	while (nn > 0)
	{
		*(sn + (nn - 1)) = '0' + num_extract(n, k);
		nn--;
		k = k * 10;
	}
	if (check > 0)
	{
		*(sn) = '-';
		if (check == 2)
			*(sn + nn_bis - 1) = (int)(*(sn + nn_bis - 1) + 1);
	}
	*(sn + nn_bis) = '\0';
}

void	caso_min_value(int *n, size_t *check)
{
	if (*n == -2147483648)
	{
		*n = (*n + 1) * (-1);
		*check = *check + 1;
	}
	else
		*n = *n *(-1);
}

char	*ft_itoa(int n)
{
	size_t	nn;
	char	*sn;
	size_t	check;

	nn = nn_gen(n);
	check = 0;
	if (n < 0)
	{
		check++;
		sn = (char *)malloc(sizeof(char) * (nn + 2));
		if (!sn)
			return (NULL);
		caso_min_value(&n, &check);
	}
	else
	{
		sn = (char *)malloc(sizeof(char) * (nn + 1));
		if (!sn)
			return (NULL);
	}
	num_alloc(sn, nn, n, check);
	return (sn);
}
