/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:59:52 by fprosper          #+#    #+#             */
/*   Updated: 2022/04/14 11:31:09 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}	
	while (i < n && (*(s1 + i) != '\0' || *(s2 + i) != '\0'))
	{
		if ((*(s1 + i)) != *(s2 + i))
		{
			return \
				((*(unsigned char *)(s1 + i)) - (*(unsigned char *)(s2 + i)));
		}
		i++;
	}
	return (0);
}
