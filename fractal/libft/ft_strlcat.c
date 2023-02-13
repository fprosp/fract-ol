/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:07:45 by fprosper          #+#    #+#             */
/*   Updated: 2022/04/13 14:27:47 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ldst;

	i = 0;
	ldst = ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
	{
		return (dstsize + ft_strlen(src));
	}
	while (i + 1 < (dstsize - ldst) && *(src + i) != '\0')
	{
		*(dst + ldst + i) = *(src + i);
		i++;
	}
	*(dst + ldst + i) = '\0';
	return (ldst + ft_strlen(src));
}
