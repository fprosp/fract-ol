/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:48:54 by fprosper          #+#    #+#             */
/*   Updated: 2022/05/09 16:36:00 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s1)
		return (NULL);
	while (i < ft_strlen(s))
	{
		*(s1 + i) = f(i, *(s + i));
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
